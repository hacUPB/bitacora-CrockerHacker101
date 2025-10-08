# Actividad 1

### 1. ¿Qué es una lista enlazada y en qué se diferencia de un arreglo en cuanto a la forma en que los elementos están almacenados en la memoria?

Una lista enlazada es una estructura de datos en la que cada elemento (nodo) contiene un valor y un puntero al siguiente nodo.

- En arreglos, los elementos están almacenados de forma contigua en memoria, con posiciones fijas.  
-En listas enlazadas, los elementos pueden estar dispersos en memoria y se conectan mediante punteros.  

- Diferencia clave: Los arreglos permiten acceso rápido por índice (O(1)), pero son poco flexibles al insertar/eliminar y las listas enlazadas permiten inserciones y eliminaciones eficientes (O(1) en cabeza o cola), pero acceso más lento (O(n) al recorrer).

### 2. ¿Cómo se vinculan los nodos entre sí? ¿Qué estructura se utiliza?  

Los nodos se vinculan a través de punteros, en este programa:

"Node* next;"

Cada nodo tiene un puntero (next) que apunta al siguiente nodo de la lista. Esto permite recorrer la lista nodo por nodo.

### 4. ¿Qué ventajas ofrece una lista enlazada frente a un arreglo en inserciones o eliminaciones intermedias?

- En un arreglo, insertar/eliminar en medio requiere mover todos los elementos posteriores → O(n).  
- En una lista enlazada, solo necesitas cambiar punteros → O(1).  
Ejemplo: si quieres insertar un nodo en medio de la lista, basta con modificar next de los nodos cercanos.

### 5. ¿Cómo se asegura que no haya fugas de memoria en este código?
   
Gracias al destructor de LinkedList:
"
LinkedList::~LinkedList() {
    clear();
}
"

Cuando un objeto LinkedList se destruye, automáticamente se llama a clear(), que libera todos los nodos con delete.
Esto garantiza que toda la memoria usada se devuelva.

### 6. ¿Qué sucede en la memoria al invocar clear()?  

Paso a paso:  

- Se empieza desde head.  
- Guarda la dirección del siguiente nodo en una variable temporal (nextNode).  
- Se elimina el nodo actual con delete.  
- Se avanza al siguiente nodo (current = nextNode).  
- Repite hasta que la lista queda vacía.  
- head y tail se ponen en nullptr, y size = 0.  
Resultado: todos los nodos son liberados, evitando fugas de memoria.  

### 7. ¿Qué ocurre en memoria al agregar un nuevo nodo al final de la lista?  

Se crea un nodo con new, El puntero next del último nodo (tail) se actualiza para apuntar al nuevo nodo.  

- El nuevo nodo pasa a ser la nueva tail.  

- Esto no requiere mover nodos, pero sí implica recorrer hasta el final si no se guarda el tail.  
Rendimiento: agregar al final es O(1) si tienes un puntero tail, O(n) si tienes que recorrer desde head.  

### 8. Ejemplo de situación donde es mejor una lista enlazada que un arreglo   

Si haces un programa que manipula elementos dinámicos (ejemplo: simulación de partículas que entran y salen del sistema), Con un arreglo, cada vez que elimines un elemento tendrías que mover todos los siguientes → costoso. Con una lista enlazada, basta cambiar punteros → mucho más eficiente.

### 9. Aplicación del manejo de memoria en un proyecto creativo  

Si estás diseñando una estructura para arte generativo (por ejemplo, una animación de partículas que se crean y destruyen dinámicamente):

Usar listas enlazadas permite manejar partículas que aparecen/desaparecen sin reorganizar grandes bloques de memoria.

Consideraciones:
Asegurar delete cuando un nodo ya no se necesita.  
Usar destructores bien definidos para liberar memoria automáticamente.  

### 10. Diferencias de gestión de memoria: C++ vs C#

En C++, el programador tiene control total con new y delete.

- Ventaja: eficiencia máxima.

- Desventaja: si olvidas delete, hay fugas de memoria.

En C#, existe un garbage collector que libera memoria automáticamente.

- Ventaja: menos errores de memoria.

- Desventaja: menos control, y pausas cuando el recolector limpia memoria.

### 11. Consideraciones para listas enlazadas en arte generativo

- Evitar fugas liberando memoria en clear() o destructores, Controlar bien la creación/eliminación de nodos, ya que habrá muchos cambios dinámicos.

- Optimizar el recorrido si hay miles de nodos (ejemplo: usar listas dobles o punteros extras).

### 12. ¿Cómo probar el programa y sus partes?

- Prueba unitaria de addNode: verificar que size aumenta y que tail apunta al nuevo nodo.

- Prueba de clear(): añadir varios nodos, llamar a clear() y comprobar que head == nullptr, tail == nullptr, size == 0.

- Prueba de update(): mover el mouse y comprobar que los nodos siguen la posición.

- Prueba de integración: correr todo el programa, mover el mouse y presionar la tecla c para limpiar.

- Con el depurador de Visual Studio, puedes poner puntos de interrupción y ver en tiempo real cómo cambian head, tail, size y los punteros de los nodos.

  

# Actividad 2  

### 1: Entendiendo la aplicación:  
Clase Node:

```
class Node {
public:
    ofVec2f position;
    Node* next;

    Node(float x, float y) {
        position.set(x, y);
        next = nullptr;
    }
};
```

Propósito: Representar un nodo individual en la pila.  
Atributos:
- position — guarda la posición 2D (x,y) donde se dibujará un círculo.  
- next — puntero al siguiente nodo en la pila (conexión en la lista enlazada).  
Constructor: Inicializa la posición con los valores x y y recibidos y deja next en nullptr porque cuando se crea un nodo no tiene siguiente aún.

Clase Stack
```
class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        clear();
    }

    void push(float x, float y) {
        Node* newNode = new Node(x, y);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void clear() {
        while (top != nullptr) {
            pop();
        }
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            ofDrawCircle(current->position.x, current->position.y, 20);
            current = current->next;
        }
    }
};
```

Atributos:
- top — puntero al nodo que está en la cima de la pila (último insertado).  
- Constructor: Inicializa top a nullptr (pila vacía).  
- Destructor: Llama a clear() para eliminar todos los nodos y liberar memoria.  
push(x, y):
Crea un nuevo nodo con la posición dada, el nuevo nodo apunta hacia el nodo que estaba en la cima (newNode->next = top).  
Actualiza top para que apunte al nuevo nodo, Esto significa que el nuevo nodo se convierte en el primero en la pila.

pop():

Si la pila no está vacía (top != nullptr):

Guarda temporalmente el nodo actual en temp.  
Actualiza top para apuntar al siguiente nodo (top = top->next).  
Elimina el nodo antiguo (delete temp), liberando memoria.  
Esto remueve el nodo de la cima de la pila.  

clear():

Mientras la pila no esté vacía, hace pop() repetidamente para liberar todos los nodos.


display():
Recorre desde top hasta el final (nullptr).
Para cada nodo, dibuja un círculo en la posición almacenada (ofDrawCircle).

# Preguntas de reflexión para el stack:

## 1. ¿Cómo se gestiona la memoria en una implementación manual de un stack en C++?
En la implementación manual del stack, cada nodo se crea dinámicamente con `new` y se libera con `delete`.  
Esto significa que el programador es responsable de gestionar la memoria, lo que ofrece flexibilidad pero también riesgos.  
Si se olvida liberar memoria, ocurren fugas. Además, el uso frecuente de `new` y `delete` puede afectar el rendimiento, ya que el sistema debe asignar y liberar bloques de memoria muchas veces.


## 2. ¿Por qué es importante liberar la memoria cuando se desapila un nodo en un stack?
Al desapilar, si no se llama a `delete` sobre el nodo, este sigue ocupando memoria aunque ya no sea accesible.  
Esto provoca fugas de memoria, que en programas de larga duración (como instalaciones artísticas o simulaciones) pueden consumir toda la RAM y hacer que la aplicación falle.  
Liberar memoria mantiene el programa seguro, eficiente y estable.

### 3. ¿Qué diferencias existen entre usar un stack de la STL (std::stack) y crear un stack manualmente?
- **`std::stack` (STL)**  
  - Maneja automáticamente la memoria.  
  - Más seguro y confiable para producción.  
  - Menos control sobre los detalles internos.  

- **Stack manual (como en el código)**  
  - El programador controla la estructura interna (enlaces, nodos, etc.).  
  - Permite personalizar el comportamiento (ej. dibujar nodos en arte generativo).  
  - Mayor riesgo de errores de memoria.  

En conclusión: STL simplifica, manual da control.


### 4. ¿Cómo afecta la estructura de un stack al orden de acceso y eliminación de elementos?
Un stack sigue el modelo **LIFO (Last In, First Out)**.  
Esto significa que el último elemento en entrar es el primero en salir.  
Este comportamiento es útil en problemas como:
- Manejo de deshacer (Ctrl+Z).  
- Evaluación de expresiones matemáticas.  
- Recorrido en profundidad (DFS).  

En el código de arte generativo, esto se refleja en que el último círculo apilado es el primero en desaparecer.


### 5. ¿Cómo podrías modificar el stack para almacenar tipos de datos más complejos?  
Se puede modificar el `Node` para que almacene objetos con múltiples atributos, por ejemplo:

```cpp
class Node {
public:
    MyCustomObject data; // objeto complejo
    Node* next;

    Node(const MyCustomObject& obj) : data(obj), next(nullptr) {}
};
```
En este caso hay que considerar:

- Usar constructores y destructores adecuados para evitar fugas  
- Si los objetos usan memoria dinámica internamente, asegurarse de copiar o moverlos correctamente (constructor de copia/movimiento).  
- Si se usan punteros, emplear smart pointers (std::unique_ptr, std::shared_ptr) para evitar fugas de memoria.  

Esto haría el stack más flexible sin comprometer la seguridad.


