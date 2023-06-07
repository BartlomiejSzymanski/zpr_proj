Requirements for gRPC used in this project:
```
install grpc from this link:
https://grpc.io/docs/languages/cpp/quickstart/
```

to build

```
cd build 
cmake ../
make
```

To generate the server 
```
pwd == zpr_proj/backend/

protoc -I=proto --cpp_out=src/game_grpc --grpc_out=src/game_grpc --plugin=protoc-gen-grpc=[/path/to/grpc_cpp_plugin] game.proto
```
[/usr/bin/grpc_cpp_plugin]
protoc -I=proto --cpp_out=src/game_grpc --grpc_out=src/game_grpc --plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin game.proto