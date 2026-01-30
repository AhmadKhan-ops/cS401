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
        self.subcate: Set["ItemCate"] = set()

    def get_name(self):
        return self.name
    def get_itemlist(self):
        return self.itemlist
    def get_subcate(self):
        return self.subcate
    def add_item(self, item: archINVIN):
        self.itemlist.add(item)
    def add_subcate(self, subcate : "ItemCate" ):
        self.itemlist.add(subcate)

class Volleyball(archINVIN):
    def __init__ (self, name, price, availability, material, VolleyBallsize):
        super().__init__(name, price, availability)
        self.material = material
        self.VolleyBallsize = VolleyBallsize
    def over(self):
        print("VolleyBall -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Material: ",self.material,"Size: ",self.VolleyBallsize )


class VolleyballNET(archINVIN):
    def __init__ (self, name, price, availability,  NetType):
        super().__init__( name, price, availability)
        self.NetType = NetType
    def over(self):
        print("VolleyBall Net -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Type: ",self.NetType )

class Table(archINVIN):
    def __init__ (self, name, price, availability, Tablesize):
        super().__init__( name, price, availability)
        self.Tablesize = Tablesize
    def over(self):
        if self.availability == 0:
            print("Not enough tables to play table tennis")        
        print("Table -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Size: ",self.Tablesize )  
        

class Paddle(archINVIN):
    def __init__ (self, name, price, availability,  PaddleType):
        super().__init__( name, price, availability)
        self.PaddleType = PaddleType
    def over(self):
        print("Table tennis paddle -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Type: ",self.PaddleType )
        if self.availability < 2:
            print("Not enough Paddles to play table tennis")


class TableBall(archINVIN):
    def __init__ (self, name, price, availability,):
        super().__init__( name, price, availability)
    def over(self):
        print("Table tennis ball -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability)
        if self.availability == 0:
            print("Not enough balls to play table tennis")    


class Tent(archINVIN):
    def __init__ (self, name, price, availability, durability, weather_rating, Tentsize):
        super().__init__(name, price, availability)
        self.durability = durability
        self.Tentsize = Tentsize
        self.weather_rating = weather_rating
    def over(self):
        print("Tent -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Size: ",self.Tentsize, "Weather Rating: ",self.weather_rating, "Durability: ",self.durability )


class Soccerball(archINVIN):
    def __init__ (self, name, price, availability, Soccermaterial, teamsize):
        super().__init__(name, price, availability)
        self.Soccermaterial = Soccermaterial
        self.teamsize = teamsize
    def over(self):
        if self.teamsize > 10:
            print("Enjoy a 15 percent discount on Soccerballs!")
            self.price = self.price * .85
        if self.teamsize > 25:
            print("Enjoy a 30 percent discount on Soccerballs!")
            self.price = self.price * .70      

        print("SoccerBall -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Material: ",self.Soccermaterial )


class SoccerNET(archINVIN):
    def __init__ (self, name, price, availability,  SoccerSize, teamsize):
        super().__init__(name, price, availability)
        self.SoccerSize = SoccerSize
        self.teamsize = teamsize
    def over(self):
        if self.teamsize > 10:
            print("Enjoy a 15 percent discount on Soccer Nets!")
            self.price = self.price * .85
        if self.teamsize > 25:
            print("Enjoy a 30 percent discount on Soccer Nets!")
            self.price = self.price * .70  
        print("Soccerball Goal Net -> Name: ",self.name, "Price: ", self.price, " Avability: ", self.availability,"Size: ",self.SoccerSize )










Indoor_Sports = ItemCate("Indoor Sports")
Outdoor_Sports = ItemCate("Outdoor Sports")

Volley_Ball = Volleyball("Super Cool Volleyball", 67, 4, "metal", "large")
Volley_Net = VolleyballNET("Normal Volleyball Net", 15, 6, "rope")
Table_ = Table("Table Tenis basic Table", 200, 3, "large")
Paddle_ = Paddle("Worn Down paddle", 6, 1, "Beginner")
Table_T_Ball = TableBall("4 pck of Balls", 4, 10)

Camp_tent = Tent("Extreme Tent", 400, 1, "Exremely Durable", "Large","Suited for extreme Weather")
Soccer_Ball = Soccerball("Normal SoccerBall", 20 , 30, "Iron Plastic", 18)
Soccer_Net = SoccerNET("SoccerBall Net", 80 , 6 , "medium", 18)

Indoor_Sports.add_item(Volley_Ball)
Indoor_Sports.add_item(Volley_Net)
Indoor_Sports.add_item(Table_)
Indoor_Sports.add_item(Paddle_)
Indoor_Sports.add_item(Table_T_Ball)

Outdoor_Sports.add_item(Camp_tent)
Outdoor_Sports.add_item(Soccer_Ball)
Outdoor_Sports.add_item(Soccer_Net)
