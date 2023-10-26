# 1 submodule
git 的 submodule 作为一个独立的 repo, 其拥有普通 repo 全部的功能, 我们可以完全按照普通的 repo 管理命令来进入 submodule 中进行手动管理. 不过如果存在多个 submodule 位于同一 superproject 下时, 掌握一些 git submodule ... 命令就变得尤为重要了.


- 子模块(submodule)添加方法
例如需要将 submodule1 开源代码添加到自己的代码仓库中
****
    1. git submodule add https://github.com/seaside-play/submodule1.git

- 进入你想将 submodule1 添加到的目录
在该目录下执行
上述命令执行之后会将对应的 submodule 代码下载下来。
这时在仓库的根目录会有新增一个 .gitmodules 文件
提交子模块到远程仓库
到这里 submodule1 子模块就添加到自己的仓库了，


    在主工程中更新仓库后，submodule工程只有文件夹，没有内容。需要初始化一下，命令如下：
    1. git submodule init # 进行注册
    2. git submodule update # 切出代码来，从git本地仓库中的代码切到工作目录下

- 代码更新
    
    一般在创建git仓库之后，会生成一个main分支，本地的分支为master，切换到main之后，使用
    git rebase master 直接将main中的代码rebase为master的代码，
    之后，使用git push -f强推本地代码到服务器上，至此完成了main和master远程的首次连接。
    之后，master修改代码并提交服务器之后，就可以执行服务器端的合并请求。以保证main分支的代码，总是是被合并，
    而不是通过本地人为添加的。

    子模块修改完代码并提交服务器之后，再在主仓库中进行代码的stage和commit操作。


## 1.1 需求

本地已建立仓库且很多提交信息。之后需要推向远端，而远端尚未建立，或者合并到其它仓库中。最佳实践：
在远程服务器上创建新分支，再将本地分支和新分支关联。之后作为submodule，合并到主仓库中。

    git branch -a
    git checkout -b v1.0.0 # create local branch v1.0.0
    git push --set-upstream origin v1.0.0  # 创建远程分支，并且本地分支关联远程分支
    git branch -a # 查看本地和远程的分支
    git branch -vv # 确认是否正确，查看本地分支关联的远程分支

[git创建远程分支并关联本地分支](https://blog.csdn.net/longfeng995/article/details/128478961)

1. 场景1：本地和远程都没有分支
2. 场景2：本地有分支和远程没有分支
3. 场景3：本地没有分支和远程有分支
4. 场景4：本地和远程都有分支
  但是它们需要进行关联

    git remote -v # 查看远程仓库url 还有一种方法就是：
    git remote show  git remote show origin
    git branch --set-upstream-to=origin/master # 默认就会将本地仓库关联到远程的origin/master仓库。这里的origin就可以使用远程仓库的url。

    git push -u http://192.168.x.x:1234/user/***.git master
    表示将本地分支强制推送到远端，就是与远端建立连接。效果类似于：
    git push origin master
    git branch --set-upstream master orgin/master
    但是，本地并没有与远程连接联系，只是把本地代码推送到了远端

- 本地切换到远程分支
    将远程的分支信息先fetch下来放到本地仓库中，然后再进行如下命令，创建本地分支与远程分支之间的关联：
    
    git checkout -b master1 origin/master # master1本地新建的分支，origin/master远程分支在本地的分支名
    git branch -r #查看远程分支在本地的仓库名


# 2 Git查看远程分支详解
### 一、Git查看远程分支地址
要查看远程分支的地址，可以使用git remote show命令。该命令将列出每个远程仓库及其相关信息，包括远程分支的名称和URL。

git remote show [remote name]， 也可以没有remote name
例如，要查看名为origin的远程库的信息：

git remote show origin

### 二、Git查看远程分支命令
要查看远程分支的列表，可以使用git branch命令，并使用-r选项限制显示仅为远程分支。

git branch -r
如果要查看包含远程分支在内的所有分支列表，可以使用-a选项。

git branch -a
### 三、Git查看远程分支从哪创建出来的
要查看远程分支的来源，可以使用git show-branch命令。

git show-branch [remote branch name]
例如，要查看远程分支origin/feature的来源分支：

git show-branch origin/feature
### 四、Git查看远程分支怎么退出
如果您错切了分支，可以使用git checkout命令切换到正确的分支。

git checkout [branch name]
### 五、Git查看远程分支来源
要查看远程分支的来源，可以使用git log命令并将分支名称作为参数。

git log [remote branch name]
例如，要查看远程分支origin/feature的历史记录：

git log origin/feature
### 六、Git查看远程分支丢失
如果您在本地找不到远程分支，可能是由于没有将其与本地分支关联或者该分支不存在于远程仓库中。

要查看是否存在分支丢失，可以使用git branch命令，并使用-v选项查看每个分支的最新提交信息。

git branch -v
### 七、Git切换远程分支
要将本地分支切换到远程分支，可以使用git checkout命令，并将远程分支名称作为参数。

git checkout [remote branch name]
注意，此时可能会产生一个“无分支”的警告。这是因为您当前位于一个游离状态的HEAD，您必须先创建一个本地分支并将其关联到远程分支，然后才能切换到该分支。

### 八、Git拉取远程分支到本地
要将远程分支拉取到本地，可以使用git pull命令，并将远程分支名称作为参数。

git pull [remote name] [remote branch name]:[local branch name]
例如，要将远程分支origin/feature拉取到本地分支feature中：

git pull origin feature:feature
### 九、Git查看远程所有分支
要查看远程仓库中所有的分支，可以使用git ls-remote命令。

git ls-remote [remote name]
例如，要查看名为origin的远程仓库中的所有分支：

git ls-remote origin
### 十、Git怎么关联远程分支
要将本地分支与远程分支关联并推送更改，可以使用git push命令，并指定远程分支名称。

git push -u [remote name] [local branch name]:[remote branch name]
例如，要将本地分支feature与远程分支origin/feature关联：

git push -u origin feature:feature
本文介绍了Git查看远程分支的多个方面，包括查看远程分支地址、查看远程分支命令、查看远程分支的来源、切换远程分支、拉取远程分支到本地、查看远程所有分支、关联远程分支等。希望能够帮助读者更好地使用Git管理源代码。
