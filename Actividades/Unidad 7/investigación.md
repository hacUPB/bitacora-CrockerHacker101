# Actividad 1  

### Que son los vertices ?
En el 3D, un vértice es un punto en el espacio 3D que determina la figura de un objeto. Cada vértice posee atributos que están relacionados, tales como:  
Como las Texturras, Coordenadas y Color  

### ¿Con qué figura geométrica se hace un dibujo en 3D?
Los triángulos es usada en la geometría de cada objeto 3D se descompone en una malla de triángulos.

### ¿Qué es un shader?
son programas que se ejecutan en la GPU y se encargan de controlar la apariencia visual de los gráficos por ordenador, como la iluminación, las texturas, los colores y los efectos especiales. Permiten a los artistas y desarrolladores definir cómo los objetos en un modelo 3D interactúan con la luz y cómo se renderizan los píxeles para crear imágenes finales más realistas o estilizadas.  

### ¿Qué es un fragment shader?  
Un fragment shader es un tipo de programa que se encarga de determinar el color de los fragmentos generados durante el proceso de rasterizacion

### ¿Qué es un vertex shader?  
Un vertex shader es un tipo de programa que se encarga de procesar los vertices de un modelo 3D antes de que se conviertan en fragmentos para el render.

### ¿Al proceso de determinar qué pixels del display va a cubrir cada triángulo de una mesh se le llama?  
A este proceso se le llama Rasterizacion. Esta es la etapa final de un renderizado donde las figuras geometricas se convierten en fragmentos.
Durante la rasterizacion el sistema grafico evalua cada triangulo y determina que pixeles en la cuadricula de la pantalla estan dentro de los limites de este.

### ¿Qué es el render pipeline?
El render pipeline o tubería de renderizado es la secuencia de pasos que un motor gráfico sigue para convertir datos tridimensionales en una imagen bidimensional final. Es una cadena de operaciones que maneja la transformación de la escena 3D, desde el modelo 3D hasta la representación en pantalla, e incluye la gestión de las transformaciones espaciales, las texturas, la iluminación y el color.   

### ¿Hay alguna diferencia entre aplicar un color a una superficie de una mesh o aplicar una textura?
Si hay varias diferencias entre aplicar un color a una superficie de una malla y aplicar una textura.  
Aplicar color Aplicar un color a una superficie implica asignar un valor de manera uniforme en toda esta, lo que significa que no hay variaciones basadas en la geometria o los detalles.  
El color es uniforme en toda la superficie, lo que significa que no hay variaciones basadas en la geometria o detalles de la superficie y tambien aplicar un color es un proceso menos "pesado" a comparacion de aplicar texturas, ya que no requiere de lectura de datos de textura.  
Aplicacion de textura Aplicar una textura implica mapear una imagen (o un conjunto de estas) sobre la superficie de la malla. Esta imagen puede contener detalles mas complejos como patrones, colores y variaciones que se aplican segun las coordenadas de estas texturas.

### ¿Cuál es la diferencia entre una textura y un material?  
Textura:  
- ¿Qué es? Es una imagen 2D (mapa de bits) que se envuelve alrededor de un objeto 3D para darle una superficie realista, como si fuera la corteza de un árbol o el patrón de una tela.   
- ¿Qué hace? Define el detalle visual de la superficie de un objeto, píxel a píxel, para generar patrones y texturas específicas.   

Material:
- ¿Qué es? Es el conjunto de propiedades y parámetros que rigen la apariencia de un objeto, incluyendo cómo se comporta bajo la luz.    
- ¿Qué hace? Define cómo se ve la superficie en general. Puede ser brillante, mate, translúcido, opaco, etc. Un material usa a menudo texturas para sus propiedades, pero también tiene otros valores intrínsecos.  

### ¿Qué transformaciones se requieren para mover un vértice del 3D world al View Screen?  
Al mover un vertice en un espacio 3D al View Screen, se necesitamos tres transformaciones clave: 
- primero, la transformación de modelo que lleva los vértices del espacio local al espacio de mundo, aplicando operaciones como traslación, rotación y escalado;
- segundo, la transformación de vista, que posiciona y orienta la cámara en la escena, convirtiendo las coordenadas del espacio de mundo al espacio de vista.
- finalmente, la transformación de proyección, que convierte las coordenadas 3D del espacio de vista en coordenadas 2D del espacio de clip, utilizando una matriz de proyección adecuada.

### ¿Al proceso de convertir los triángulos en fragmentos se le llama?
Es la Rasterización, esta es el proceso de convertir un objeto gráfico vectorial, como un dibujo o texto, a un formato de mapa de bits o ráster, que se compone de una cuadrícula de píxeles. Esta conversión transforma las ecuaciones matemáticas que definen las formas en una imagen formada por pequeños puntos de color, haciéndola compatible con pantallas y dispositivos de impresión.  

### ¿Qué es el framebuffer?  
Un framebuffer es un área de memoria de acceso aleatorio RAM que contiene los datos de píxeles de una imagen completa que se va a mostrar en la pantalla. Funciona como un "lienzo" digital donde se dibuja un fotograma antes de enviarlo al monitor, permitiendo manipular y renderizar la imagen en segundo plano antes de su visualización.

### ¿Para qué se usa el Z-buffer o depth buffer en el render pipeline?  
El Z-buffer (también llamado depth buffer) se usa en el render pipeline para manejar la profundidad de los objetos en una escena 3D, es decir, cuál objeto está delante y cuál está detrás al momento de renderizar la imagen final.

# Actividad 2
Usamos el codigo proporsionado por el examples, el resultado es el siguiente:  


<img width="1299" height="1004" alt="image" src="https://github.com/user-attachments/assets/936457f9-3883-4974-b980-38d89daea130" />


yo le hice una modificaciones al codigo ese, lo unico que modifique fue el color, lo unico que hice fue modificar el valor del color (puse 0)


<img width="1277" height="1007" alt="image" src="https://github.com/user-attachments/assets/278f3e5d-8fe5-4763-a840-3324c0eea61f" />

### ¿Cómo funciona?  
Este codigo funciona con un shader cargado por openframewors, setup se encarga de cargar los archivos del shader y draw se encarga de dibujar los shaders, y estos comienzan con shader begin.  
Cada vértice del rectángulo pasa por el vertex shader, que calcula su posición en pantalla usando una matriz de transformación (modelViewProjectionMatrix). Luego, cada píxel del rectángulo pasa por el fragment shader, que calcula su color según su posición (gl_FragCoord): el valor rojo depende de la coordenada X y el verde de la Y y ya azul es constante y asi ese que se da ese efecto en la pantalla.

### ¿Qué resultados obtuviste?
Las capturas estan al inicio de esta actividad chajaja no manches.

### ¿Estás usando un vertex shader?
Si, en el ejemplo se usa un vertex shader pero de manera muy simple, este solo se encarga de posicionar los vertices del triangulo en la pantalla

### ¿Estás usando un fragment shader?
Si, tambien se usa un fragment shader y este ya si se encarga de calcular los colores y generar ese efecto we.

# Actividad 3 

el efecto base del codigo es el siguiente:  
<img width="1406" height="1075" alt="image" src="https://github.com/user-attachments/assets/8618097a-4d1f-4d9b-8a30-7b1965c038d2" />

una maya ondulada de color azul we, decidi por ponerle un color veige mas o menos, pero se nota un poco:

<img width="1332" height="1021" alt="image" src="https://github.com/user-attachments/assets/73aee4c6-28c1-4cde-94e9-f0829b416ce1" />

### ¿Qué es un uniform?   
Un uniform es una variable que permite enviar info desde el programa hacia los shaders, de modo que todos los vertices o fragmentos usen el mismo valor durante un cuadro. A diferencia de las variables que cambian por pixel o vertice, un uniform mantiene un valor constante mientras ejecuta este shader. Esto permite que se puedan pasar valores como el tiempo, la posicion del mouse o el tamaño de la ventana para generar animaciones o efectos visuales dinamicos


# Actividad 4
### ¿Que hace el codigo de ejemplo?  
El codigo dado crea una especie de animación que tiene unos colores que van cambiando, el shader se encarga de enviar datos del tiempo con (ofGetElapsedTimed()), el vertex del tiempo lo so para modificar los color y asi genero un patron para que de el efecto visual.

### ¿Cómo funciona el código de aplicación, los shaders y cómo se comunican estos?
La aplicación carga el shader, actualiza el tiempo y lo envía como uniform para generar una animación. En setup() se carga el shader, y en draw() se activa, se pasa el tiempo con setUniform1f("time", ofGetElapsedTimef()), y se dibuja una figura. El vertex shader calcula la posición de los vértices y el fragment shader usa el tiempo para cambiar los colores con funciones, creando efectos visuales animados.




