import pandas as pd
left = pd.DataFrame({
   'id':[1,2,3,4,5],
   'Name': ['Alex', 'Amy', 'Allen', 'Alice', 'Ayoung'],
   'subject_id':['sub1','sub2','sub4','sub6','sub5']})
print(left)
right = pd.DataFrame({
   'tid':[101,201,301,401,501,601,701],
   'Name': ['Alex', 'Brian', 'Amy', 'Bryce', 'Alice','RKP','DKP'],
   'subject_id':['sub2','sub4','sub3','sub6','sub5','SUB10','SUB11']})
print(right)
pd1=pd.merge(left, right, on='Name', how='left')
print (pd1)
pd1=pd1.drop(['subject_id_y'], axis=1)
pd1=pd1.rename(columns={"subject_id_x": "subject_id"})
print(pd1)
pd2=pd1['tid'].isnull()
pd2=pd.merge(pd2, right, on='subject_id', how='left')
print(pd2)