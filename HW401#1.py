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
      def get_name(self):
        return self.availability

      @abstractmethod
      def over(self):
        pass 

class ItemCate:
    def __init__(self,name):
        self.name = name
        self.itemlist: Set[archINVIN] = set()
        self.subcate: Set[Category] = set()

    def get_name(self):
        return self.name
    def get_itemlist(self):
        return self.itemlist
    def get_subcate(self):
        return self.subcate
    def add_item(self, item:ArchINVIN):
        self.itemlist.append(item)
    def add_subcate(self, subcate : Category):
        self.itemlist.append(subcate)


