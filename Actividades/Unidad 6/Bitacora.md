# Bitacora: Unidad 6 análisis de un caso de estudio 

### Primero void a responder la pregunta, ¿que hace este programa?:  

es un sistema de particulas, que pueden cambiar si se presiona alguna tecla, las teclas son:    

- 's'  stop: todas las partículas se detienen.    
- 'a'  attract: todas las partículas son atraídas hacia el puntero del mouse.    
- 'r'  repel: todas las partículas huyen del puntero del mouse.    
- 'n' normal: las partículas vuelven a moverse con su velocidad aleatoria.  

todo esto se logra con:  

- State pattern  cada partícula tiene un "estado" (NormalState, AttractState, RepelState, StopState) que define cómo se actualiza su movimiento.  
- Observer pattern  todas las partículas observan a la app principal, y esta les notifica cuando hay un evento de teclado.  
### ¿Qué hace el Observer Pattern en este código?  

El patrón Observer se usa para que la clase ofApp (que hereda de Subject) pueda notificar a todas las partículas a la vez cuando ocurre un evento.

Subject (ofApp)

Tiene una lista de observadores (observers), que en este caso son todas las partículas.

Cuando se presiona una tecla, llama a notify("evento").

Observer (Particle)

Cada partícula implementa onNotify(const std::string& event).

Cuando recibe la notificación, cambia de estado:

- "attract"  AttractState  
- "repel"  RepelState  
- "stop"  StopState  
- "normal"  NormalState  

Flujo de notificación:  

El usuario presiona 'a'.  

- ofApp::keyPressed() ejecuta notify("attract").   
- Subject::notify() recorre todos los observers (partículas).  
- Cada partícula recibe onNotify("attract") y cambia su estado a AttractState.  
- En el siguiente update(), todas se comportan como partículas que van hacia el mouse  

### El Factory es el encargado de crear partículas de diferentes tipos (estrellas, planetas, estrellas fugaces) con sus características predefinidas.

Centraliza la creación: en lugar de que ofApp tenga que decir “hazme una partícula, ponle color rojo, tamaño pequeño y velocidad X”, simplemente pide:

Particle* p = ParticleFactory::createParticle("star");

ventajas  
- Evita duplicación de código: todas las reglas para inicializar partículas viven en un solo lugar (ParticleFactory).  
- Facilita agregar más tipos: si mañana quieres un nuevo tipo "comet", solo lo agregas dentro de ParticleFactory y el resto del programa no cambia.  
- Hace el código más limpio y mantenible: ofApp::setup() solo se preocupa de cuántas partículas crear, no de cómo configurarlas.  

### ¿Qué hace el patrón state en este caso?  

En este código, el State Pattern controla cómo se comporta cada partícula dependiendo del estado en el que esté.
En lugar de tener un "if" o "switch" gigante en update(), cada estado se encarga de definir su propia lógica.

Estados que existen son los siguientes:

- NormalState la partícula se mueve con una velocidad aleatoria normal.  
- AttractState la partícula es atraída hacia el puntero del mouse.  
- RepelState la partícula se aleja del puntero del mouse.  
- StopState la partícula queda completamente quieta.  

¿Cómo funciona?  

La partícula tiene un puntero a su estado actual (state), luego, en cada frame (update()), delega el comportamiento a ese estado despues cuando se presiona una tecla (a, r, s, n), el estado de todas las partículas cambia (setState(...)).  

Así, el comportamiento cambia en tiempo real sin modificar el código principal de Particle.

### Modificación del codigo original:

lo que hice fue agregarle unas cuantas funciones y detalles para hacerlo un poco diferente al codigo original.   
Lo que agrege fue:  

A: modo atracción  
R: modo repulsión  
S: detener  
N: normal  
E: explosión  
ademas las particulas ahora son cometas.  

Prueba video:  

