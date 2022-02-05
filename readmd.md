# 설치한거
`code .`를 처음 실행하면 설치되는 vs code 서버  
'c++ extension pack' (ms-vscode.cpptools-extension-pack)  
`sudo apt-get install build-essential gdb`로 컴파일러와 디버거 설치  
nvm 설치 (https://github.com/nvm-sh/nvm)
nvm으로 nodejs lts (v16) 설치  

# 컴파일
- 둘중 하나
  + `g++ -c shared.cpp -fPIC -o shared.o`, `g++ shared.o -shared -o shared.so`: cpp -> o -> so
  + `g++ -fPIC shared.cpp -shared -o shared.so`: cpp -> so
+ main: `g++ main.c++ -o main -ldl`  
