This app was created using the tutorial from : https://docs.djangoproject.com/en/4.2/intro/tutorial01/

Before running, make sure that you're inside /zpr_proj/web_interface/
To run application use the following commands:

```
python manage.py runserver
```

To run tests:

```
python manage.py test
```

To generate gRPC files:
```
> cd web_interface/main_menu
>python3 -m grpc_tools.protoc -I protos --python_out=. --grpc_python_out=. protos/game.proto
```
game_pb2_grpc.py and game_pb2.py should appear in the web_interface/main_menu folder
