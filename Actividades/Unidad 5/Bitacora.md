# Actividad 01

### punto 1

- La Clase Particle representa un modelo de particula 2D y su posición mediante X e Y
- Aqui lo atributos guardan la posicion actual del objeto y los metodos modifican el estado para hacer cositas como mover la particula we
- según chajepete...

"¿Qué es una clase en C++?

Una clase es una plantilla o un molde que define un tipo de dato complejo que agrupa datos (atributos) y funciones (métodos) que operan sobre esos datos. Piensa en una clase como el plano de una casa: define cómo es la estructura, pero no es la casa en sí.

En tu ejemplo:
```
class Particle {
public:
    float x, y;              // atributos (posiciones)
    void move(float dx, float dy) {  // método para mover la partícula
        x += dx;
        y += dy;
    }
};
```
Aquí Particle es la clase que describe qué es una partícula:  

- Tiene dos atributos, x e y, que representan su posición.  
- Tiene un método move que permite cambiar la posición sumando un desplazamiento dx y dy.  

¿Qué es un objeto en C++?

Un objeto es una instancia concreta de una clase. Es decir, cuando creas un objeto, estás creando un ejemplar real basado en el molde que define la clase.  
Siguiendo con la analogía, si la clase es el plano, el objeto es la casa construida con ese plano.  

Por ejemplo:

```
Particle p1;   // p1 es un objeto de tipo Particle
p1.x = 0;
p1.y = 0;

p1.move(5, 3);  // ahora p1 está en la posición (5, 3)
```

Aquí:

p1 es un objeto de la clase Particle.

- Tiene sus propios valores para x e y.  
- Puedes usar el método move para modificar esos valores.  
- Cada objeto tiene su propio conjunto de atributos independientes de otros objetos."  

### Reflexión guida  

 
<img width="1113" height="627" alt="C__Users_B09S115est_Downloads_of_v0 12 1_vs_64_release_apps_myApps_mySketch_bin_mySketch_debug exe 15_09_2025 5_28_22 p  m" src="https://github.com/user-attachments/assets/d4ace67c-9602-447a-a69e-a3630a9e6d87" />

# Analisis de Diferencias:  

<img width="1113" height="627" alt="C__Users_B09S506est_Downloads_of_v0 12 1_vs_64_release_of_v0 12 1_vs_64_release_apps_myApps_prueba_bin_prueba_debug exe 17_09_2025 4_41_09 p  m" src="https://github.com/user-attachments/assets/4b53c753-5b3a-4c50-bb42-fb7951bb9425" />

este es el resultado poner el script sin los datos dinamicos:

<img width="1113" height="627" alt="Consola de depuración de Microsoft Visual Studio 17_09_2025 4_43_52 p  m" src="https://github.com/user-attachments/assets/3a171978-3364-42d5-bd9b-30e0a4f03821" />

este es el resultado cuando pongo el script con los datos dinamicos 

### ¿Cómo afectan los datos estáticos al tamaño de la instancia?  

En este caso los datos NO afectan al tamaño de la instancia, lo que afecta al tamaño en si es la clase static, eso es lo que afecta el tamaño de de la instancia.  

### ¿Qué diferencias hay entre datos estáticos y dinámicos en términos de memoria?  

- los datos estaticos se quedan en la memoria global del programa (como .data) mientras que en los dinamicos estan en heap.  
- en los estaticos solo hay una copia en toda la clase, sin importar el numero de instancias, mientras que en las dinamicas cada instancia puede tener su propia copia de la clase en la memoria heap.  
- en los datos estaticos su tiempo de vida es desde que inicia el programa hasta que da por finalizado, mientras que en los dinamicos "viven" desde que se inicia el programa hasta que se ponga (delete), y si no se libera hay una fuga de memoria.


### Prompt para ChatGPT: explícame cómo el uso de variables estáticas y dinámicas en una clase afecta el tamaño de sus instancias. ¿Las variables estáticas ocupan espacio en cada objeto?  

***Variables normales:***  
- Ocupan espacio dentro de cada objeto. Sí afectan el sizeof.

***Variables estáticas (static):***    
- No forman parte de los objetos, hay una sola copia compartida para toda la clase. No afectan el sizeof.  

***Variables dinámicas (punteros + new):***  
- En el objeto solo está el puntero (sí cuenta en el sizeof).  
- La memoria reservada con new vive aparte en el heap, no dentro del objeto.  

### Reflexión  

Objeto en memoria:  
es un bloque que guarda los atributos propios de la clase, solo contiene variables de instancia y punteros si hay memoria dinamica.

Influencia de atributos y métodos:  
- Normales: ocupan espacio en cada objeto.  
- Estáticos: no ocupan espacio en el objeto, hay una sola copia global.  
- Dinámicos: solo se guarda el puntero en el objeto; la memoria real está en el heap.  
- Métodos: no afectan el tamaño, se comparten entre instancias.  

Conclusión:  
El tamaño de un objeto depende de sus atributos de instancia y punteros, no de los estáticos ni métodos. Esto impacta el diseño de clases porque obliga a decidir cuándo usar memoria compartida (estática), propia (normal) o flexible (dinámica)

# Seccion 2

### ¿Dónde se almacenan los datos y métodos de una clase en C++ en la memoria? Explica el concepto de vtable y cómo se relaciona con los métodos virtuales.  

- los datos en c++ se guardan en la memoria como parte de cada objeto (heap, stack). Si se guarda en "Stack" se almacena en la pila, si se guarda como "new" en "heap"  se guarda en el monton.  
- los metodos no se almacenan en un objeto, todos los objetos llaman a la misma función, pasando de manera implícita el puntero this que apunta al objeto que invoca la función.  
- al usar los métodos virtuales, entra en juego un mecanismo especial: la tabla virtual (vtable).

¿Qué es la vtable?:   
es una tabla (array interno generado por el compilador) que guarda punteros a funciones virtuales de la clase, cada clase que tenga al menos un método virtual tiene su propia vtable, en cada objeto de esa clase, el compilador coloca un puntero oculto llamado vptr que apunta a la vtable de la clase.  
¿Cómo funciona?:  
cuando llamas a un método no virtual, la llamada se resuelve en tiempo de compilación (estática), cuando llamas a un método virtual, el compilador busca en el vtable a través del puntero vptr para saber qué función ejecutar (despacho dinámico).

***Tambien se puede usar vptr*** 

vptr (puntero virtual) es un puntero oculto que el compilador añade automáticamente en cada objeto de una clase con métodos virtuales.  
cada objeto tiene un vptr, ese vptr apunta a la vtable de su clase, cuando llamas a un método virtual, el programa sigue este puntero para consultar en la vtable cuál función debe ejecuta

### Exploración de métodos virtuales  

#### ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?  

cuando una clase no tiene métodos virtuales, su objeto contiene únicamente sus atributos de datos y cuando una clase tiene métodos virtuales, el compilador usamos el vptr.    
este puntero apunta a la vtable (virtual table) correspondiente a la clase. El tamaño del objeto aumenta en, al menos, el tamaño de un puntero (4 bytes en sistemas de 32 bits, 8 bytes en sistemas de 64 bits).  

- b ocupa tamaño = sizeof(Base) = vptr + atributos (si tuviera).  
- d ocupa tamaño = sizeof(Derived) = vptr + atributos (si tuviera).  

#### ¿Qué papel juegan las vtables en el polimorfismo?  

La vtable es una tabla generada por el compilador que guarda direcciones de funciones virtuales para cada clase y cada clase con metodos virtuales tiene su propia vtable.  
Cada objeto tiene un vptr que apunta a la vtable de su clase.

- "b.vptr" apunta a la vtable de Base, que contiene la dirección de Base::display
- "d.vptr"  apunta a la vtable de Derived, que contiene la dirección de Derived::display

#### Según chajepete:   

Es una tabla de punteros a funciones generada por el compilador para cada clase que contiene métodos virtuales, cada clase que tiene métodos virtuales mantiene una vtable única, con entradas que apuntan a las implementaciones actuales de esos métodos, cada objeto de una clase con virtuales guarda un puntero oculto, llamado vptr (virtual table pointer), que apunta a la vtable de su clase.  

¿Cómo funcionan los métodos virtuales y la vtable?   
- Declaración del método virtual: Cuando declaras un método como virtual en una clase base, le indicas al compilador que esta función puede ser anulada por las clases derivadas.  
Creación de la vtable:   
- El compilador crea una tabla virtual (vtable) por cada clase que tiene al menos una función virtual. Esta vtable es una matriz estática que contiene punteros a la definición más específica de cada función virtual disponible para la clase.   
- Creación del vptr: Cada objeto de una clase con funciones virtuales recibe un puntero oculto, llamado vptr, como parte de sus datos. Este vptr se inicializa para que apunte a la vtable de la clase del objeto. 

### Uso de punteros y referencias  

- El tamaño de la instancia crece solo lo que ocupa el puntero a función, la función suele ocupar el mismo tamaño que un puntero normal (4 bytes en sistemas de 32 bits, 8 bytes en 64 bits) y las funciones estáticas (staticFunction) no se almacenan en el objeto, se almacenan en la sección de código del programa. Ademas el tamaño de la instancia no cambia aunque tengas funciones estáticas o normales: lo que cambia es si agregas o no miembros (como el puntero).  

- "funcPtr" almacena la dirección en memoria de la función asignada (en este caso staticFunction), esa dirección apunta al bloque de código máquina correspondiente a la función, no guarda una copia de la función, sino simplemente la referencia a dónde está definida en la memoria de código.  

- se usa un puntero a función normal, no un puntero a método de instancia, En clases con herencia polimorfica, el compilador genera una vtable (tabla de funciones virtuales). Cada objeto contiene un puntero oculto a esa tabla para saber qué implementación ejecuta.  

En rendimiento, la diferencia respecto a llamadas directas es mínima, aunque en casos críticos puede ser relevante.

#### Según chajepete  

Si solo necesitas funciones "libres", usa punteros a función (más simples y más pequeños).
Si necesitas enlazar comportamiento dependiente de un objeto, usa punteros a métodos miembro (más flexibles, aunque un poquito más costosos).  

### Reflexión   
mientras hacia este punto descubri que:
- cuándo usar herencia, punteros o funciones estáticas.
- evitar abusar del polimorfismo donde no hace falta.
- diseñar sistemas más rápidos y predecibles en consumo de recursos.

# Sección 3

## Herencia y la Relación en Memoria  

¿Cómo los objetos derivados contienen los datos de las clases base?:   
Cuando defines una clase derivada en C++ (u otros lenguajes similares), el objeto de la clase derivada contiene en su interior la parte correspondiente a la clase base, en memoria, obj tiene primero el bloque de datos de Base (con x) y después los de Derivada (con y), así que un objeto derivado "contiene" al objeto base como su primera parte.

Desplazamiento en memoria      
cuando se construye el objeto derivado, los atributos de la clase base se ubican primero en memoria (respetando alineación/padding), y luego siguen los de la clase derivada.  
- a y b (de Base) aparecen primero.  
- Luego c (de Derivada) está después.  
Esto se llama desplazamiento en memoria: los atributos de la base ocupan los primeros bytes, y los de la derivada se agregan al final.  

### ¿Cómo se organizan los atributos en memoria?:   
En memoria, d se organiza como si tuviera todos los atributos de Base seguidos por los de Derived, en orden de herencia y después en orden de declaración.  

- &d  coincide con &(d.baseVar) porque el primer miembro del objeto es el subobjeto Base.
- &(d.baseVar)  primera posición en memoria.
- &(d.derivedVar)  después de baseVar (respetando alineación/padding).

### ¿Qué sucede si agregamos más niveles de herencia?  

el orden seria:

- Primero los miembros de la clase base más lejana (A).  
-  Luego los de la siguiente clase base (B).  
- Finalmente los de la clase más derivada (C).   

y tambien:

- &obj == &(obj.a) (porque el subobjeto más base empieza en la misma dirección).  
- &(obj.b) estará después de a.  
- &(obj.c) estará después de b.  

### Según chajepete  

- 1. Organización en memoria de clases sin herencia

En C++, cuando defines una clase, sus atributos (variables miembro) se almacenan en memoria de manera contigua dentro de cada objeto.

- 2. Con herencia (sin polimorfismo)

Cuando una clase hereda de otra, los atributos de la clase base se almacenan primero, como si fueran la primera parte del objeto derivado.
Después se colocan los atributos de la clase derivada.

- 3. Con polimorfismo (herencia con métodos virtuales)

Cuando la clase base tiene al menos una función virtual, aparece en memoria un puntero oculto llamado vptr (Virtual Table Pointer), que apunta a la tabla de funciones virtuales (vtable).

- 4. Puntos clave

Los atributos de la clase base forman la primera parte del objeto derivado.

Luego vienen los atributos propios de la clase derivada.

Si hay funciones virtuales, aparece un puntero oculto vptr en la parte inicial (su ubicación puede variar según el compilador, pero suele estar al comienzo).

Los accesos como &d == &d.baseVar suelen ser verdaderos si no hay herencia múltiple ni virtual, porque el primer miembro del objeto derivado es la base.
