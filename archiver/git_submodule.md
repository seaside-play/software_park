# 指定子仓库分支

如果你要指定一个不同的分支，可以编辑.gitmodules文件，找到对应的子模块条目，并添加或修改branch属性来指定要使用的分支。例如：

ini
[submodule "<子模块路径>"]  
    path = <子模块路径>  
    url = <子仓库URL>  
    branch = <指定分支名>
保存.gitmodules文件后，使用以下命令来更新子模块到指定的分支：

bash
git submodule sync  
git submodule update --remote <子模块路径>
