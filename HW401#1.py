from abc import ABC, abstractmethod
from typing import Set
class archINVIN(ABC):
      
      def __init__(self, name, price, availability):
                self.name = name
                self.availability = availability
                self.price = price 
      def get_name(self):
        return self.name
      def get_price(self):
        return self.price 
      def get_availability(self):
        return self.availability

      @abstractmethod
      def over(self):
        pass 

class ItemCate:
    def __init__(self,name):
        self.name = name
        self.itemlist: Set[archINVIN] = set()
        self.subcate: Set[ItemCate] = set()

    def get_name(self):
        return self.name
    def get_itemlist(self):
        return self.itemlist
    def get_subcate(self):
        return self.subcate
    def add_item(self, item: archINVIN):
        self.itemlist.add(item)
    def add_subcate(self, subcate : ItemCate):
        self.itemlist.add(subcate)

class Volleyball(archINVIN):
    def __init__ (self, material, VolleyBallsize):
        super().__init__(name, price, availability)
        self.material = material
        self.VolleyBallsize = VolleyBallsize
  

class VolleyballNET(archINVIN):
    def __init__ (self,  NetType):
        super().__init__( name, price, availability)
        self.NetType = NetType

class Table(archINVIN):
    def __init__ (self, Tablesize):
        super().__init__( name, price, availability)
        self.Tablesize = Tablesize
  

class Paddle(archINVIN):
    def __init__ (self,  PaddleType):
        super().__init__( name, price, availability)
        self.PaddleType = PaddleType

class TableBall(archINVIN):
    def __init__ (self, amount):
        super().__init__( name, price, availability)
        self.amount = amount

class Tent(archINVIN):
    def __init__ (self, durability, weather_rating, Tentsize):
        super().__init__(name, price, availability)
        self.durability = durability
        self.Tentsize = Tentsize
        self.weather_rating = weather_rating

class Soccerball(archINVIN):
    def __init__ (self, Soccermaterial):
        super().__init__(name, price, availability)
        self.Soccermaterial = Soccermaterial

class SoccerNET(archINVIN):
    def __init__ (self, SoccerSize):
        super().__init__(name, price, availability)
        self.SoccerSize = SoccerSize











Indoor_Sports = ItemCate("Indoor Sports")
Outdoor_Sports = ItemCate("Outdoor Sports")

Volley_Ball = Volleyball("Super Cool Volleyball", 67, 4, "metal", "large")
Volley_Net = Volleyball("Normal Volleyball Net", 15, 6, "rope")
