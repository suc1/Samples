# Building Java applications

[Gradle 7.5.1](https://docs.gradle.org/current/userguide/getting_started.html)

## [ssl error](https://stackoverflow.com/questions/9619030/resolving-javax-net-ssl-sslhandshakeexception-sun-security-validator-validatore)
[remove ca-certificates-java and install it again](https://stackoverflow.com/questions/29584328/gradlew-bat-and-gradlew-sslhandshakeexception#answer-30924895)
```
sudo dpkg --purge --force-depends ca-certificates-java
sudo apt-get install ca-certificates-java

./gradlew clean
```

```
keytool -list -keystore "$JAVA_HOME/lib/security/cacerts"
sudo keytool -delete -alias ledsmart -keystore "$JAVA_HOME/lib/security/cacerts"

sudo keytool -import -noprompt -trustcacerts -alias ledsmart -file ledsmart2.crt -keystore "$JAVA_HOME/lib/security/cacerts" -storepass changeit

sudo keytool -import -noprompt -trustcacerts -alias gradle -file gradle.org.crt -keystore "$JAVA_HOME/lib/security/cacerts" -storepass changeit

sudo keytool -import -noprompt -trustcacerts -alias bintray.com -file bintray.com -keystore "$JAVA_HOME/lib/security/cacerts" -storepass changeit

sudo keytool -import -noprompt -trustcacerts -alias USERTrustRSA -file "USERTrust RSA Certification Authority.crt" -keystore "$JAVA_HOME/lib/security/cacerts" -storepass changeit
```
## [Building Java Applications Sample](https://docs.gradle.org/7.5.1/samples/sample_building_java_applications.html)
1. `gradle init`
2. 子工程: settings.gradle: `include('app')`
3. 应用程序的主类: app/build.gradle, `application { mainClass = 'demo.App' }`
4. command:
```
./gradlew clean
./gradlew build
./gradlew run

./gradlew check			#运行测试
./gradlew :app:check
```
## [Building Java Libraries](https://docs.gradle.org/current/samples/sample_building_java_libraries.html)
1. build.gradle:
```
version = '0.1.0'
tasks.named('jar') {
    manifest {
        attributes('Implementation-Title': project.name,
                   'Implementation-Version': project.version)
    }
}
```
2. command:
```
./gradlew build
./gradlew jar
```

## [Building Java Applications with libraries](https://docs.gradle.org/current/samples/sample_building_java_applications_multi_project.html)
1. settings.gradle: `include('app', 'list', 'utilities')`
2. buildSrc是可重用的构建配置. 
    1. buildSrc/src/main/groovy/demo.java-common-conventions.gradle是共享的配置
	2. buildSrc/src/main/groovy/demo.java-library-conventions.gradle是库的配置, `id 'java-library'`
	3. buildSrc/src/main/groovy/demo.java-application-conventions.gradle是可运行程序的配置, `id 'application'`
3. app/build.gradle, 依赖`implementation project(':utilities')`
4. list/build.gradle
5. utilities/build.gradle, 依赖`api project(':list')`
6. 最多包含三个块: plugins; dependencies('', project); 插件可能有一个或多个配置块
7. buildSrc/build.gradle: 

## Build & Run on ubuntu
1. bash: ./gradlew: Permission denied: `chmod +x gradlew`
2. `git add -f gradle/wrapper/gradle-wrapper.jar`

## 再加一个新库: lib2
