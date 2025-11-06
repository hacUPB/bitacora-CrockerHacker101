# RETO 7

### Primero intente usar unos shaders que hice en mi casita.  
estos me dieron error por que no pase el main.cpp



"Usare el codigo de un ejemplo dado por el OpenFrameworks", en este caso usare el ejemplo 3 ya que es el mas me gusto de todos, y se ve melo caramelo


<img width="832" height="245" alt="image" src="https://github.com/user-attachments/assets/4df630a1-d429-4a8a-a027-53aeb0dd2806" />


lo primero que hice fue cambiarle los colores ya que los base no me gustaban:


<img width="645" height="115" alt="image" src="https://github.com/user-attachments/assets/60d508e5-93cb-4ab8-9f39-f89fa68d75ae" />

cambie los valores por "black" y "yellow" para que le de un toque de viejo que queda con la imagen que seleccione

<img width="606" height="96" alt="image" src="https://github.com/user-attachments/assets/d49c352c-dbb5-4c3c-9032-0833a2b50bd9" />

y la imagen que puse fue la siguiente:

![chad](https://github.com/user-attachments/assets/16bf46e0-3782-4e54-9735-48b8880edce8)

tuve errores ya que el formato de la foto no lo aceptaba el OpenFrameworks, originalmente era un .WEBP y me toco buscar por chatgpt que me ayudara, ahi me dijo que era por el tipo del archivo, asi que solo tuve que cambiarle el formato a .JPG y melos

primero empeze editan ofApp.h ya que era lo mas brevesito.
Asi que pase de esto:





A esto:

<img width="908" height="473" alt="image" src="https://github.com/user-attachments/assets/988065bf-f096-4dfa-9727-ccc4eeb55ca7" />

despues cambie el ofApp.cpp  



por esto:  

<img width="557" height="673" alt="image" src="https://github.com/user-attachments/assets/acb55239-9da1-4a24-a16f-0691471259a4" />




Despues cambie el shader.frag 


Por este
<img width="1283" height="593" alt="image" src="https://github.com/user-attachments/assets/c1f4f5cd-d5b2-468b-b47c-049f8c4fcc6f" />


Y por ultimo cambie le archivo shader.vert


Por este:

<img width="837" height="673" alt="image" src="https://github.com/user-attachments/assets/38eef29f-805f-4c7f-965f-ae6b333c805a" />

tras todos los cambios al final me quedo la actividad de la siguiente forma:


tuve errores ya que el formato de la foto no lo aceptaba el OpenFrameworks, originalmente era un .WEBP y me toco buscar por chatgpt que me ayudara, ahi me dijo que era por el tipo del archivo, asi que solo tuve que cambiarle el formato a .JPG y melos

Ahora respondiendo la pregunta de cuando la CPU le manda info a la GPU.
Un ejemplo de esto en mi codigo son las siguientes lineas:
```
shader.begin();
shader.setUniformTexture("tex0", chad.getTexture(), 0);
shader.setUniform1f("mouseRange", 150);
shader.setUniform2f("mousePos", mx, my);
shader.setUniform4fv("mouseColor", mouseColor);
plane.draw();
shader.end();
```

¿Por que?  
R/ esto es porque la CPU activa el programa de shaders en la GPU y le dice “usa este programa para los próximos vértices y fragmentos” esto en shader.begin().    
o en plane.draw() hace que la CPU le dice a la GPU “dibuja estos vertices", OpenFrameworks envia una orden glDrawArrays o glDrawElements, y la GPU procesa los vértices, ejecuta el vertex shader para cada uno, y luego el fragment shader para cada pixel.  
tambien en shader.end() la CPU le dice a la GPU que pare.

Link del video de muestra:  
https://youtu.be/kkFpYFBDZY0  
