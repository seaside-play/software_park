当你合并两个分支时，可以旋转带有--squash参数的合并，将所有提交并入一个提交。通过这种方式合并分支，以后不能撤销分支合并。基于这个考虑，只有在合并你本来就不希望分离的分支时，才使用--squash。

- 将试验性分支合并回主分支
    git checkout master
    git merge experimental_idea --squash
    git commit 
    在合并之后，就可以删除你的试验性分支啦