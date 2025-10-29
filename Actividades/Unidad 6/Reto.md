# Reto Unidad 6  

Primero se me ocurrio la idea de un temblor, por que justo estaba viendo unos reels, y se me ocurrio esta idea.

empeze el codigo poniendo 3 estados, uno que este estable y no tiemble, otro que tiemble un poco y que al pasar 20 segundos se caigan los edificios, le puse un sistema de gravedad y un sistema de debris (escombros) en particulas que caigan al suelo y luego desaparesca.  
el tercer estado es casi lo mismo, solo que tiembla mas duro y los edificios caigan a los 5 segundos.

pruebas acontinuacion:  


### Primer estado:  
<img width="1024" height="768" alt="Screenshot 8_10_2025 5_01_23 p  m" src="https://github.com/user-attachments/assets/85206457-05fa-4ab0-bc86-47fbb74dbb08" />  

### Segundo estado:  
<img width="1024" height="768" alt="Screenshot 8_10_2025 5_01_33 p  m" src="https://github.com/user-attachments/assets/7339cb8d-e56c-4d0e-85f9-dbe75ea57d68" />  

### Tercer estado:  
<img width="1024" height="768" alt="Screenshot 8_10_2025 5_01_40 p  m" src="https://github.com/user-attachments/assets/6c4cfa48-af7d-480d-84f6-85df0185d187" />

### Imagen de los escombros cayendo:  
<img width="1024" height="768" alt="Screenshot 8_10_2025 5_01_58 p  m" src="https://github.com/user-attachments/assets/39ef1ff2-2551-455b-bfc6-895e8912c24a" />

al mostrarle al profe, me dio una idea de hacer fabrica de unos carros para darle mas jugo al codigo, mi idea es que segun el estado los carros (que van a ser circulos) se aplasten a 1/4 en el segundo estado y a la mitad en el tercer estado.

le agrege lo siguiente en OfApp.h  

```
// ---------- CAR ----------
class Car : public Observer {
public:
	ofVec2f pos;
	float radius;
	ofColor color;
	bool crushed = false;
	float baseRadius;
	float scaleY = 1.0f;  // escala vertical

	Car(ofVec2f p, float r, const ofColor & c)
		: pos(p)
		, radius(r)
		, color(c)
		, baseRadius(r) { }

	void onNotify(const std::string & event) override {
		if (event == "reset" || event == "reconstruir") {
			crushed = false;
			scaleY = 1.0f;
		}
	}

	void update() {
		// Por ahora no hay física para carros, solo estado de aplastado.
	}

	void draw() const {
		ofSetColor(color);
		ofPushMatrix();
		ofTranslate(pos.x, pos.y);
		ofScale(1.0f, scaleY);
		ofDrawCircle(0, 0, radius);
		ofPopMatrix();
	}
};

// ---------- CAR FACTORY ----------
class CarFactory {
public:
	static std::shared_ptr<Car> createCar(const ofVec2f & pos, float r, const ofColor & c) {
		return std::make_shared<Car>(pos, r, c);
	}
};
```  
esto es para crear el carro  

En Buidling state le puse lo siguiente:  

```
protected:
	std::vector<std::shared_ptr<Building>> * buildings;
	std::vector<std::shared_ptr<Car>> * cars;  // <-- nuevo
	Subject * subject;
	ofColor baseColor1, baseColor2;
	float quakeForce = 0;
	float collapseTime = 0;
	std::string name;

public:
	BuildingState(std::vector<std::shared_ptr<Building>> * b, std::vector<std::shared_ptr<Car>> * c, Subject * s,
		ofColor c1, ofColor c2, float force, float collapse, std::string n)
		: buildings(b)
		, cars(c)
		, subject(s)
		, baseColor1(c1)
		, baseColor2(c2)
		, quakeForce(force)
		, collapseTime(collapse)
		, name(std::move(n)) { }
```
esto hace que

y en draw() le puse esto:  

```
void draw() override {
	for (const auto & b : *buildings)
		b->draw();

	for (const auto & car : *cars)
		car->draw();
}
```

asi quedaron los carros:  

<img width="1010" height="787" alt="Captura de pantalla 2025-10-08 173920" src="https://github.com/user-attachments/assets/71dbcf3f-0c07-40f3-a583-0dd25da3e994" />


