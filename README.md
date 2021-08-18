# coupe2022
Repo for enac robotique 2022

# Organisation 

## arduino_bouton

Code pour l'expérience/la girouette/l'objet statique qui doit être actionné par un bouton par le robot et qui doit faire des trucs après.

## arduino_robot

Code de bas niveau sur les robots, controllant les moteurs, servomoteurs et autres actuateurs du robot nécessitant du temps réel, ainsi que les capteurs. Exception possibles, branchés directement au haut niveau : le lidar, une camera,....

A compiler avec **platformio**, le dossier est organisé en fonction de platformio aussi.

### src/examples

codes de diagnostic, facilement activable/intégrable au robot à tout moment en cas de pépin : de quoi refaire l'asservissement, investiger le serial, l'I2C,...

## raspberry_robot

Code de la raspberry sur les robots, contenant un dossier src à mettre dans **ROS2**, et contiendra un autre dossier pour la configuration de la rapsberry, et d'autres codes/utilitaires.

Contient les outils de navigation, les state machines,...

## raspberry_girouette

Code pour la girouette, à voir plus tard.



## electronic

Gros dossier regroupant tous les designs de carte electronique de l'année, chaque sous dossier correspond aux fichiers d'une carte. Prévus pour Kicad.

## ros_desktop

Codes/utilitaires en lien avec ros, à utiliser sur les ordis pour configurer, debugger, ou simuler les robots.

## doc

Documentations du code, faites avec **doxygen**, prévues pour arduino_robot, raspberry_robot, raspberry_girouette et ros_desktop.

## 

