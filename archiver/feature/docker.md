- 学习网站
https://www.runoob.com/docker.../docker-install-ubuntu.html

        $ docker pull ubuntu # 拉取最新版的 Ubuntu 镜像  
        $ docker images # 查看本地镜像  
        $ docker run -itd --name ubuntu-test ubuntu 运行容器，并且可以通过 exec 命令进入 ubuntu 容器
        $ docker exec -it ubuntu-test /bin/bash
        docker ps   # 安装成功

- 更新必要的资源信息
  
        apt-get udpate # 在容器内部，首先更新列表，然后安装编译工具和依赖
        apt-get install -y build-essential

        下载并编译llvm
        从llvm官网现在源码，解压，然后编译安装