[ Tutorials and Video ]
https://www.youtube.com/watch?v=xuB1Id2Wxak 
--command
https://github.com/joshnh/Git-Commands/blob/master/README.md

============================================
Git Commands
==============================================
[ Create a local repository ]
--------------------------------------------------------------------------------------------
git init
git remote add origin [remote repository URL]
or 
git clone [ remote repository URL ]
------
git remote -v
# Verifies the new remote URL
git remote -v

[ Branch ]
--------------------------------------------------------------------
# List  branch/branches
git branch
git branch -a
git branch -r

# List remote branches information
git remote
git ls-remote
* git remote show origin
git ls-remote --heads origin

# switch a branch
git checkout [branch name]

[ Show branches and their commits ]
---------------------------------------------------------------------------
The following example shows three branches, "master", "fixes" and "mhf":
git show-branch master fixes mhf
