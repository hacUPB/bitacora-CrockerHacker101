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





