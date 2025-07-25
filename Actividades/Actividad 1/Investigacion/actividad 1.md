# Actividad 1

## ¿Qué es un computador digital moderno?
Un computador digital moderno es una máquina electrónica capaz de recibir, procesar y almacenar datos mediante operaciones lógicas y aritméticas, usando valores binarios (0 y 1). Está diseñado para ejecutar programas que controlan su funcionamiento y le permiten realizar tareas específicas.

## ¿Cuáles son sus partes?
Un computador moderno se compone principalmente de:

- **Unidad Central de Procesamiento (CPU)**: Es el cerebro del computador. Procesa las instrucciones de los programas.
- **Memoria (RAM)**: Almacena temporalmente los datos y programas que están siendo utilizados.
- **Dispositivo de almacenamiento**: Guarda datos de forma permanente.   
- **Ej**: discos duros (HDD), unidades de estado sólido (SSD).
- **Dispositivos de entrada**: Permiten al usuario ingresar información.  
- **Ej**: teclado, mouse, escáner.
- **Dispositivos de salida**: Muestran el resultado del procesamiento.   
- **Ej**: monitor, impresora, altavoces.
- **Placa base (motherboard)**: Conecta y permite la comunicación entre todos los componentes.
- **Fuente de poder**: Provee energía eléctrica a todo el sistema.

---

# Actividad 2 (Bitácora)

## ¿Qué es entonces un programa?
Un programa es un conjunto de instrucciones escritas en un lenguaje de programacion que una computadora puede interpretar y ejecutar para realizar una tarea especifica.

## ¿Qué es un lenguaje ensamblador?
Un lenguaje ensamblador (Assembly) es un lenguaje de bajo nivel que traduce directamente a instrucciones comprensibles por la CPU, pero usando palabras clave simbolicas en lugar de solo números binarios. Es más entendible para los humanos que el lenguaje de máquina, pero sigue estando muy cerca del hardware.

Ejemplo de una instrucción en ensamblador:

## MOV AX, 5 ; Mueve el valor 5 al registro AX

# Actividad 3  
## ¿Qué son PC, D y A?  
- **Personal Computer**: Computadora personal. Es un dispositivo electrónico usado por una sola persona a la vez, con capacidad para ejecutar programas, navegar por internet, jugar videojuegos, etc.  
- **A** = Acumulador  
Nombre del registro: AX, EAX o RAX (dependiendo de si es de 16, 32 o 64 bits).
Es el registro principal que se usa para operaciones aritméticas y lógicas. Se llama así porque históricamente era el que “acumulaba” resultados.  
  
- **D** = Data (registro de datos)    
Nombre del registro: DX, EDX o RDX.  
Se usa para operaciones que requieren un segundo registro junto con AX/EAX/RAX.  
Por ejemplo:  
En multiplicaciones y divisiones, DX se usa para almacenar parte del resultado (como el residuo).
