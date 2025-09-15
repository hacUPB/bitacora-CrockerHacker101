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



