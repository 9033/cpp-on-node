# 실행환경
+ OS: WSL - Ubuntu 20.04.1 LTS, Windows 10
+ gcc: 9.3.0

# 설치
+ Windows 10
  - Windows Subsystem Linux - Ubuntu 20 LTS
  - Visual Studio Code
    - 'c++ extension pack' (ms-vscode.cpptools-extension-pack)  
+ Ubuntu - WSL
  - editor
    - `code .`를 처음 실행하면 설치되는 vs code 서버  
  - C++
    - `sudo apt-get install build-essential gdb`로 컴파일러와 디버거 설치  
  - node
    - nvm 설치 (https://github.com/nvm-sh/nvm)
    - nvm으로 nodejs lts (v16) 설치  

# 실행
+ `npm run test`
+ 필요시 `npm run build`로 shared.so를 빌드

# 기타

## git, npm
`git init`후 git에 리모트 repo.를 지정하고 `npm init`를 하면 package.json에 자동으로 reop.의 url를 지정해 준다.

## 컴파일
- 둘중 하나
  + `g++ -c shared.cpp -fPIC -o shared.o`, `g++ shared.o -shared -o shared.so`: cpp -> o -> so
  + `g++ -fPIC shared.cpp -shared -o shared.so`: cpp -> so
+ main: `g++ main.c++ -o main -ldl`  
