void linkingNodesOfSameLevel(Node* root) 
{
    if (root==nullptr)
        return;
    Node * rightMostNode = nullptr; 
    Node* nextHead = nullptr; 
    Node* temp = root;
    while (temp != nullptr) 
    {
        if (temp->left != nullptr)
            if (rightMostNode == nullptr) 
	    {
                rightMostNode = temp->left;
                nextHead = temp->left;
            } 
	    else 
	    {
                rightMostNode->next = temp->left;
                rightMostNode = rightMostNode->next;
            }
        if (temp - > right != NULL)
	{
            if (rightMostNode == NULL) 
	    {
                rightMostNode = temp - > right;
                nextHead = temp - > right;
            } 
	    else 
	    {
                rightMostNode - > next = temp - > right;
                rightMostNode = rightMostNode - > next;
            }
        }     
        temp = temp-> next;
    }
    linkingNodesOfSameLevel(nextHead);
}


