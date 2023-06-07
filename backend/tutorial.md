Requirements for gRPC used in this project:
```
install grpc from this link:
https://grpc.io/docs/languages/cpp/quickstart/

apt install -y protobuf-compiler

```

to build the server:
```
cd build 
cmake ../
make
```

To generate the server 


```
cd backend 
mkdir build 
cd build
cmake ../ && make
cd src/server
./server  
```


