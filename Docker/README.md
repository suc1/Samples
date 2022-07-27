# Docker

Docker

## Resources
1. [Docker Tutorial for Beginners](https://www.youtube.com/watch?v=pTFZFxd4hOI)
2. [Docker Tutorial for Beginners - A Full DevOps Course on How to Run Applications in Containers](https://www.youtube.com/watch?v=fqMOX6JJhGo)
3. [wsl linux](https://docs.microsoft.com/en-us/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package)
4. Virtual Machine:VirtualBox, vmware, hyper-v(win only)
5. Containers:
6. [Docker Start](https://docs.docker.com/get-started/) 

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
docker build -t docker101tutorial .			#build a new container image
docker run -d -p 80:80 --name docker-tutorial docker101tutorial

docker ps
docker stop <the-container-id>
docker rm <the-container-id>

docker image ls
docker login
docker login registry-1.docker.io
docker tag getting-started sucdocker/getting-started
docker push sucdocker/getting-started:tagname

# https://labs.play-with-docker.com/		?????
docker run -dp 3000:3000 sucdocker/getting-started

# named volumes
docker volume create todo-db
docker run -dp 3000:3000 -v todo-db:/etc/todos getting-started
docker volume inspect todo-db

# bind mounts, provide additional data into containers

# Start a dev-mode container
docker run -dp 3000:3000 \
     -w /app -v "$(pwd):/app" \
     node:12-alpine \
     sh -c "yarn install && yarn run dev"

docker logs -f <container-id>
```
```
docker network create todo-app

docker run -d `
     --network todo-app --network-alias mysql `
     -v todo-mysql-data:/var/lib/mysql `
     -e MYSQL_ROOT_PASSWORD=secret `
     -e MYSQL_DATABASE=todos `
     mysql:5.7

# environment variables: sql
docker run -dp 3000:3000 `
   -w /app -v "$(pwd):/app" `
   --network todo-app `
   -e MYSQL_HOST=mysql `
   -e MYSQL_USER=root `
   -e MYSQL_PASSWORD=secret `
   -e MYSQL_DB=todos `
   node:12-alpine `
   sh -c "yarn install && yarn run dev"

docker exec -it <mysql-container-id> mysql -u root -p
docker run -it --network todo-app nicolaka/netshoot
dig mysql
```
```
#Docker Compose
docker-compose version
```
```
# Creating containers from scratch: https://youtu.be/8fi7uSYlOdc
# video 18:23/42:54
```