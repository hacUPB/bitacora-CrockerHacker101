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

### 2. el puntero es el circulito morado que nos da el codigo dado



