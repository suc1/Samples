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

## [Building Java & JVM projects](https://docs.gradle.org/current/userguide/building_java_projects.html)
1. 使用`Java Library Plugin`
    1. `compileJava` task compiles `src/main/java`
	2. `compileTestJava` task compiles `src/test/java`
	3. `test`
	4. `jar` generate `<project>-<version>.jar`
	5. `javadoc`
2. source sets: 自动为每个源集创建编译任务, `compileJava` = `compileOnly` + `implementation`
3. Java 项目的依赖:
    1. 存储库位置: `repositories {}`
	2. 名称和版本, 做什么: `dependencies {}`. 
	    1. 配置: compileOnly; implementation=compile+runtime; runtimeOnly; testCompileOnly; testImplementation; testRuntimeOnly; api; compileOnlyApi
		2. 使用本地文件系统目录中的依赖项
		3. 将兄弟项目声明为依赖项: `implementation project(':shared')`
4. 编译你的代码
    1. 自定义文件和目录位置
	2. 附加third-party目录路径, 附加`srcDir 'thirdParty/src/main/java'`, 替换`srcDirs = ['src']`
	3. 更改编译器选项
	4. 分别编译独立来源, 自定义源集
5. 管理资源: WriteProperties
6. 运行测试
7. 打包发行
8. 生成 API 文档
9. clean
10. 构建 JVM 组件
11. 构建 Java 库: api 公共 API; implementation 内部实现细节
12. 构建 Java 应用程序

## 再加一个新app: app2
```
mainClass = 'gradleapplib.app2.App2'

./gradlew :app:run
./gradlew :app2:run
```