class Num
  def initialize(s)
    @str = s
  end
  def seven
    Num.new(@str + '7')
  end
  def self.seven
    Num.new('7')
  end
  def two
    Num.new(@str + '2')
  end
  def self.two
    Num.new('2')
  end

  def one
    Num.new(@str + '1')
  end
  def self.one
    Num.new('1')
  end

  def three
    Num.new(@str + '3')
  end
  def self.three
    Num.new('3')
  end

  def four
    Num.new(@str + '4')
  end
  def self.four
    Num.new('4')
  end

  def five
    Num.new(@str + '5')
  end

  def self.five
    Num.new('5')
  end

  def six
    Num.new(@str + '6')
  end
  def self.six
    Num.new('6')
  end
  def eight
    Num.new(@str + '8')
  end
  def self.eight
    Num.new('8')
  end
  
  def nine
    Num.new(@str + '9')
  end
  def self.nine
    Num.new('9')
  end

  def to_i
    @str.to_i
  end

  def zero
    Num.new(@str + '0')
  end
  def self.zero
    Num.new('0')
  end
end

=begin
# Codewars
  Num = 0

  class Integer
    def zero;  self * 10 + 0 end
    def one;   self * 10 + 1 end
    def two;   self * 10 + 2 end
    def three; self * 10 + 3 end
    def four;  self * 10 + 4 end
    def five;  self * 10 + 5 end
    def six;   self * 10 + 6 end
    def seven; self * 10 + 7 end
    def eight; self * 10 + 8 end
    def nine;  self * 10 + 9 end
  end
=end
