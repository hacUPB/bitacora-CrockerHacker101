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
- Cada objeto tiene su propio conjunto de atributos independientes de otros objetos.  "
