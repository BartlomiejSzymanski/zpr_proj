# To run the game:
1. Run backend server:
2. Run frontend server:

Execute the following commands

```
cd backend 
mkdir build 
cd build
cmake ../ && make
cd src/server
./server  
```



# To run frontend server:

Prerequisites:
-Django
- gRPC for python
Before running, make sure that you're inside /zpr_proj/web_interface/

```
pip install django
pip install grpcio-tools
pip install grpcio
```
To run application use the following commands:

```
> cd web_interface/main_menu
>python3 -m grpc_tools.protoc -I main_menu/proto --python_out=. --grpc_python_out=. main_menu/proto/game.proto
```
game_pb2_grpc.py and game_pb2.py should appear in the web_interface/main_menu folder
next execute:

```
python manage.py runserver
```
```
[pwd == .../zpr_proj/]
cd web_interface
python manage.py runserver
```


localhost:8000/ is the url to access the main menu
