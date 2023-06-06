
# Prerequisites:
-Django
- gRPC for python
Before running, make sure that you're inside /zpr_proj/web_interface/

```
pip install django
pip install grpcio-tools
pip install grpcio
```
# To run application use the following commands:
```
python manage.py runserver
```

# To generate gRPC files:
```
> cd web_interface/main_menu
>python3 -m grpc_tools.protoc -I proto --python_out=. --grpc_python_out=. proto/game.proto
```
game_pb2_grpc.py and game_pb2.py should appear in the web_interface/main_menu folder

# Generate documentation for board.js:
```
sudo apt install npm 
sudo npm install -g jsdoc
jsdoc main_menu/static/js/board.js --destination doc/boardjs
```
Documentation will appear in doc/board.js

# Generate documentation for views.py:
prerequisites:
doxygen

```
sudo apt-get install graphviz
[pwd == web_interface/main_menu]
doxygen Doxyfile 
```
documentation will appear in doc/views
