from abc import ABC, abstractmethod



class archINVIN(ABC):
      def __init__(self, name, price, availability )
                self.name = name
                self.availability = availability
                self.price = price 
      def get_name(self)
        return self.name
      def get_price(self)
        return self.price 
      def get_name(self)
        return self.availability

    @abstractmethod
    def over(self):
        pass 


