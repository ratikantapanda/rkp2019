package tree;
 
import java.util.LinkedList;
import java.util.Queue;
 
public class ConnectNodesAtSameLevel{
 
 public static void main(String[] args) {
  Node rootNode=null;
 
  rootNode  = addNode(rootNode, 10, true);
  rootNode  = addNode(rootNode, 5, true);
  rootNode  = addNode(rootNode, 20, true);
 
  rootNode  = addNode(rootNode, 2, true);
  rootNode  = addNode(rootNode, 8, true);
  rootNode  = addNode(rootNode, 15, true);
  rootNode  = addNode(rootNode, 30, true);
 
  linkNodesAtSameLevelWithoutExtraSpace(rootNode);
  System.out.println(rootNode);
 }
 
 private static void linkNodesAtSameLevelWithoutExtraSpace(Node rootNode){
  // We are going to read Tree in Pre order fashion.
  // Root, nextRight, Left
 
  //if rootNode is null, return
  if(rootNode==null) 
   return;
 
  // What we are trying to do here is setting the nextRight node of next level.
  // if left child of rootNode and right child of rootNode is null, then there are no nodes further.
  if(rootNode.getLeft()==null && rootNode.getRight()==null){
   return;
  }
 
  // if left child of rootNode and right child of rootNode is not null, then left node nextRight can easily be connected to right node.
  if(rootNode.getLeft()!=null && rootNode.getRight()!=null){
   rootNode.getLeft().setNextRight(rootNode.getRight());
 
   Node tmp = rootNode.getNextRight();
   while(tmp!=null && tmp.getLeft()==null && tmp.getRight()==null){
    tmp = tmp.getNextRight();
   }
 
   // we do not found any nodes at rootNode level whose left child or right child is present.
   if(tmp==null){
    rootNode.getRight().setNextRight(null);
 
   }else if(tmp.getLeft()!=null){ // Found a node whose left child is not null, so connecting left child nextRight to it.
    rootNode.getRight().setNextRight(tmp.getLeft());
 
   }else if(tmp.getRight()!=null){ // Found a node whose right child is not null, so connecting left child nextRight to it.
    rootNode.getRight().setNextRight(tmp.getRight());
   }
    
   
  }else if(rootNode.getLeft()==null){
 
   // Only condition that can be true at this point is either leftNode can be null or rightNode can be null
   // if left child is null, then rootNode definitely has right child present.
   // if the right child is present then we need to search all the nodes at rootNode level and find the node whose left or right
   // child is not null and associate right child nextRight to it.   
 
   Node tmp = rootNode.getNextRight();
   while(tmp!=null && tmp.getNextRight()!=null && tmp.getNextRight().getLeft()==null && tmp.getNextRight().getRight()==null){
    tmp = tmp.getNextRight();
   }
 
   // we do not found any nodes at rootNode level whose left child or right child is present.
   if(tmp==null){
    rootNode.getRight().setNextRight(null);
 
   }else if(tmp.getLeft()!=null){ // Found a node whose left child is not null, so connecting right child nextRight to it.
    rootNode.getRight().setNextRight(tmp.getLeft());
 
   }else if(tmp.getRight()!=null){ // Found a node whose right child is not null, so connecting right child nextRight to it.
    rootNode.getRight().setNextRight(tmp.getRight());
   }
 
  }else{
 
   // if right child is null, then rootNode definitely has left child present.
   // if the left child is present then we need to search all the nodes at rootNode level and find the node whose left or right
   // child is not null and associate left child nextRight to it.   
 
   Node tmp = rootNode.getNextRight();
   while(tmp!=null && tmp.getLeft()==null && tmp.getRight()==null){
    tmp = tmp.getNextRight();
   }
 
   // we do not found any nodes at rootNode level whose left child or right child is present.
   if(tmp==null){
    rootNode.getLeft().setNextRight(null);
 
   }else if(tmp.getLeft()!=null){ // Found a node whose left child is not null, so connecting left child nextRight to it.
    rootNode.getLeft().setNextRight(tmp.getLeft());
 
   }else if(tmp.getRight()!=null){ // Found a node whose right child is not null, so connecting left child nextRight to it.
    rootNode.getLeft().setNextRight(tmp.getRight());
   }
  }
 
  //For the current Level, nextRight is set for all the nodes.
 
  // Reading the Left child now as nextRight is set for a cuurent level and we can go to next level.
  linkNodesAtSameLevelWithoutExtraSpace(rootNode.getLeft());
 
  // Reading the Right child now as nextRight is set for a cuurent level and we can go to next level.
  linkNodesAtSameLevelWithoutExtraSpace(rootNode.getRight());
 }
 
 private static Node addNode(Node rootNode, int i, boolean isRootNode) {
  if(rootNode==null){
   return new Node(i);
  }else{
   if(i > rootNode.getData()){
    if(isRootNode){
     Node nodeToAdd = addNode(rootNode.getRight(), i, isRootNode);
     rootNode.setRight(nodeToAdd);
    }else{
     Node nodeToAdd = addNode(rootNode.getLeft(), i, isRootNode);
     rootNode.setLeft(nodeToAdd);
    }
 
   }else{
    if(isRootNode){
     Node nodeToAdd = addNode(rootNode.getLeft(), i, isRootNode);
     rootNode.setLeft(nodeToAdd);
    }else{
     Node nodeToAdd = addNode(rootNode.getRight(), i, isRootNode);
     rootNode.setRight(nodeToAdd);
    }
   }
  }
  return rootNode;
 }
}
