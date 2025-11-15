# Actividad 02

### 1 Qué fue lo que incluimos en el archivo `.h`?
En ofApp.h se incluyó:

- `include "ofMain.h"  Trae todo lo necesario para trabajar con **openFrameworks** (ventanas, dibujo, eventos, colores, etc.)  
- La clase `ofApp` que hereda de `ofBaseApp`, donde declaramos:  
  - **Funciones del ciclo de la app:** `setup()`, `update()`, `draw()`.  
  - **Funciones de interacción:** `mouseMoved()`, `mousePressed()`.  
  - **Variables privadas:**  
    - `vector<ofVec2f> particles` → Lista de posiciones de partículas.  
    - `ofColor particleColor` → Color actual de las partículas.  

### 2 Cómo funciona la aplicación?  

- Cuando mueves el mouse, se crean "partículas" (posiciones almacenadas en un vector).  
- Se dibujan círculos en esas posiciones con el color actual.  
- Si haces click, el color de todas las partículas cambia a uno aleatorio.  
- El vector guarda máximo 100 posiciones, eliminando las más viejas para que no crezca indefinidamente.  

### 3 Que hace la función `mouseMoved`?   

- Guarda la posición (x, y) del mouse en el vector "particles"  
-S i el vector tiene más de 100 elementos, borra el primero (el más antiguo)  
- Esto hace que las partículas sigan al mouse y estén limitadas en cantidad  

### 4  Que hace la función mousePressed?  

-Cuando se presiona el mouse, cambia el color de las partículas a uno aleatorio (RGB con valores entre 0 y 255).  
-Todas las partículas cambian de color a la vez.  

###5 Que hace la función setup?  

- Se ejecuta una sola vez al inicio del programa.  
- Pone el fondo en negro (ofBackground(0)).  
- Inicializa el color de las partículas en blanco.  

### 6 Qué hace la función update?  

Aquí normalmente iría la lógica de actualización de variables o física del programa. En este caso está vacía, lo que significa que la posición de las partículas solo cambia cuando movemos el mouse  

### 7 Qué hace la función draw?  

- Recorre cada posición guardada en particles.
- Establece el color actual (particleColor).
- Dibuja un círculo de radio 50 en esa posición. Esto se repite en cada frame, manteniendo el dibujo en pantalla.

# Actividad 03  

<img width="1919" height="1032" alt="sol" src="https://github.com/user-attachments/assets/f58985b7-a95f-42b0-8ca4-cfc21651b7f0" />  

Codigo  
```c++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255);
	particleColor = ofColor::yellow;
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (auto & pos : particles) {
		ofSetColor(particleColor);
		ofDrawLine(pos.x , pos.y, 100, 100);
		ofDrawCircle(100, 100, 50);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	particles.push_back(ofVec2f(x, y));
	if (particles.size() > 100) {
		particles.erase(particles.begin());
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	particleColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}
```

# Actividad 04  

video bonito  

# Actividad 05  

### 1. ¿Cuál es la definición de un puntero?

Un puntero es una variable que almacena la direccion de memoria de otra variable u objeto, en lugar de almacenar directamente el valor.
Es decir, un puntero “apunta” a un espacio en memoria donde esta guardado un dato u objeto.

### 2. el puntero es el circulito morado que nos da el codigo dado
En este código hay dos lugares importantes donde se usan punteros:
- En el vector de esferas:  
  
´vector<Sphere*> spheres;´  
Aquí cada elemento del vector es un puntero a un objeto de tipo Sphere.  

- En la esfera seleccionada:

´Sphere* selectedSphere;´  

### 3. ¿Cómo se inicializa el puntero?  

- En setup(), las esferas se crean dinámicamente con new y se guardan en el vector de punteros:  

´spheres.push_back(new Sphere(x, y, radius));´

Esto asigna memoria en el heap y retorna un puntero a esa esfera.

- El puntero selectedSphere se inicializa como nullptr (es decir, que no apunta a nada al inicio):  

´selectedSphere = nullptr;´  

### 4.¿Para qué se está usando el puntero?  
El puntero sirve para poder mover y modificar una esfera en específico sin necesidad de copiar el objeto completo, cuando seleccionas una esfera con el mouse, el puntero selectedSphere apunta a esa esfera dentro del vector. Luego, en ´update()´, se mueve esa esfera:  
```cpp
if (selectedSphere != nullptr) {
    selectedSphere->update(ofGetMouseX(), ofGetMouseY());
}
```

### 5. ¿Qué es exactamente lo que está almacenado en el puntero?  

Este puntero almacena la direccion de memoria (Sphere), este no guarda la esfera directamente, sino su ubicacion en la RAM  

# Actividad 06   
Una vez que haces clic sobre una esfera, selectedSphere queda apuntando a ella y sigue moviéndose incluso después de soltar el mouse, Eso significa que el código no está liberando la selección cuando sueltas el mouse.

R//
debes organizar tambien mouseReleased y reiniciar el puntero cuando el botón se suelte:

En ofApp.h ponemos:  
```
void mouseReleased(int x, int y, int button);
```

En ofApp.cpp ponemos:
```
void ofApp::mouseReleased(int x, int y, int button){
    if(button == OF_MOUSE_BUTTON_LEFT){
        selectedSphere = nullptr;  // Deja de mover la esfera al soltar
    }
}
```

# Actividad 07 

### 1. ¿Qué sucede cuando presionas la tecla “c”?  
Se crea un objeto llamado Sphere  en la pila (Stack), luego se guarda su dirección (&localSphere) dentro del vector globalVector, esto es un problema porque en cuanto la función termina, localSphere deja de existir: la memoria usada para él es liberada automáticamente. Despues intentamos acceder a ese puntero almacenado en globalVector, estamos apuntando a memoria inválida, esto se llama dangling pointer.
El comportamiento resultante es indefinido: puede que veas datos corruptos, posiciones raras, o incluso que el programa se bloquee.

Al cambiar unas cositas 
¿Qué sucede cuando presionas la tecla “c”?  
Ahora el objeto se crea en el montón (heap) con new, a diferencia del stack, los objetos en el heap permanecen en memoria hasta que se liberen manualmente con delete, Esto significa que aunque termine la función, el objeto sigue existiendo y globalVector almacena un puntero válido a él.  

Así, al dibujar (sphere=draw()), realmente se visualiza la esfera sin errores ni corrupción de memoria.

### 2. ¿Por qué ocurre esto?  
Stack (pila):  
La memoria se gestiona automáticamente cuando sales de la función, los objetos locales desaparecen, guardar un puntero a un objeto local = puntero colgante (dangling pointer) → comportamiento indefinido.

Heap (montón):  
La memoria se gestiona manualmente, los objetos creados con new sobreviven más allá del alcance de la función y el puntero sigue siendo válido después de salir de la función.  

# Actividad 09   

### 1.  
Cuando presionas la tecla f, el programa elimina el último punto que hayas creado con el mouse (el más reciente) y libera la memoria asociada a ese punto. En el próximo draw() ese círculo azul (y su texto “Heap Memory”) ya no se dibuja. Si no hay puntos, no hace nada.  
```
if(!heapObjects.empty()) {
    delete heapObjects.back();
    heapObjects.pop_back();
}
```
- if(!heapObjects.empty()): evita operar sobre un vector vacío.  
- delete heapObjects.back();: libera la memoria del último puntero del vector (el ofVec2f* que se creó con new en mousePressed). Esto previene fugas de memoria.  
- heapObjects.pop_back();: quita ese puntero del vector. Así no queda un puntero colgante dentro del contenedor.  
- Importante: el orden es correcto. Primero delete, luego pop_back(). Si hicieras pop_back() primero, perderías la referencia y no podrías liberar esa memoria (fuga).

### 2. Analisis del codgo:  
```
if(!heapObjects.empty()) {
    delete heapObjects.back();
    heapObjects.pop_back();
}
```
"if(!heapObjects.empty())"
— Comprueba si el std::vector heapObjects no está vacío. empty() devuelve true cuando el vector tiene 0 elementos. Esta comprobación evita acceder a back() cuando el vector está vacío (lo cual sería UB).  
"heapObjects.back()"  
— Devuelve una referencia al último elemento del vector. En tu caso heapObjects es vector<ofVec2f*>, así que back() devuelve el último ofVec2f*.  
"delete heapObjects.back();"  
— Llama a delete sobre ese puntero: invoca el destructor del objeto apuntado (si existe) y libera la memoria asignada con new.  
— delete nullptr es seguro (no hace nada).  
— IMPORTANTE: esto sólo es correcto si el puntero fue creado con new (no con new[], ni apunta a objeto en stack, ni es alias de otra memoria manejada por otro propietario).  
"heapObjects.pop_back();"  
— Elimina el último elemento del vector (la entrada ofVec2f*). No llama a delete por sí mismo —por eso se hace delete antes— y es una operación O(1). Después de pop_back() ese puntero ya no está en el vector.  

