import math

#codigo hecho por Zárate Sifuentes Alberto Giovanni y Vergara Sandoval Gael Isaí

class CFigura:
    
    def __init__(self, lado, nlados): # __init__ para atributos privados
        self._lado= lado
        self._nlados= nlados
    
    def area(self):
        pass
    
    def perimetro(self):
        per = self._lado * self._nlados
        return per
        
    def mostrar_area(self):
        print(f"El area es: {self.area():.2f}")
        
    def mostrar_perimetro(self):
        print(f"El perimetro es: {self.perimetro():.2f}")

        
class CCuadrado(CFigura):
    
    def __init__(self, lado):
        super().__init__(lado, 4)
    
    def area(self):
        area = self._lado * self._lado
        return area

class CTriangulo(CFigura):
    
    def __init__(self, lado):
        super().__init__(lado, 3)
    
    def area(self):
        area= (self._lado* self._lado* (3**0.5)) /4
        return area

class PoligonoRegular(CFigura):
    
    def __init__(self, lado, nlados):
        super().__init__(lado, nlados)
    
    def area(self):
        if self._nlados < 3:
            return 0
        area = (self._nlados * (self._lado ** 2)) / (4 * math.tan(math.pi / self._nlados))
        return area

lado = float(input("Ingresa la medida del lado: ")) #input devuelve un string por eso la conversion de tipo con float

while lado <= 0:
    print("La medida del lado debe ser un numero positivo.")
    lado = float(input("Ingresa la medida del lado: "))

print("\nCUADRADO\n")
c=CCuadrado(lado)
c.mostrar_area()
c.mostrar_perimetro()

print("\nTRIANGULO\n")
t=CTriangulo(lado)
t.mostrar_area()
t.mostrar_perimetro()

print("\nPOLIGONO REGULAR\n")
nlados= int(input("Ingresa el numero de lados: "))

while nlados < 3:
    print("El numero de lados debe ser al menos 3.")
    nlados= int(input("Ingresa el numero de lados: "))
p=PoligonoRegular(lado, nlados)

p.mostrar_area()
p.mostrar_perimetro()