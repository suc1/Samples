# Android & java

rosjava_core (2019.4.10), android_core

## version gradle 5.0 melodic
| Product       | 2022-11-23 |
| ------------- |------------|
| openjdk       | 11.0.17    |
| Gradle        | 5.0        |
| Maven         |            |
| Groovy        | 2.5.4(集成) |
| rosjava_core  |            |
| android_core  |            |
| android       |            |

## Install openjdk 1.11
```
sudo apt install openjdk-11-jdk		#melodic

export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
export PATH=$JAVA_HOME/bin:$PATH
```

## [SDKMAN!](https://sdkman.io/install)
```
curl -s "https://get.sdkman.io" | bash
source "$HOME/.sdkman/bin/sdkman-init.sh"
sdk version			#Melodic 5.16.0
```

## Install gradle 5.0
```
sdk install   gradle 5.0

gradle -v
```