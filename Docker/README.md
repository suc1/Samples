# Docker

Docker

## Resources
1. [Docker Tutorial for Beginners](https://www.youtube.com/watch?v=pTFZFxd4hOI)
2. [Docker Tutorial for Beginners - A Full DevOps Course on How to Run Applications in Containers](https://www.youtube.com/watch?v=fqMOX6JJhGo)
3. [wsl linux](https://docs.microsoft.com/en-us/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package)
4. Virtual Machine:VirtualBox, vmware, hyper-v(win only)
5. Containers: 

## commands
```
# docs.docker.com/get-docker/
start /w "" "Docker Desktop Installer.exe" install

# "Local Users and Groups > Groups > docker-users"
net localgroup docker-users "Su Cheng" /add

docker version
```
```
# tutorial in Docker Desktop
docker run --name repo alpine/git clone https://github.com/docker/getting-started.git
cd getting-started
docker build -t docker101tutorial .
docker run -d -p 80:80 --name docker-tutorial docker101tutorial
```