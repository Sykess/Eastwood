
require 'Dungeon01'

my_dungeon = Dungeon.new("Nate")

my_dungeon.add_room(:largecave, "Large Cave", "a large cavernous cave", { :west => :smallcave } )
my_dungeon.add_room(:smallcave, "Small Cave", "a small, claustrophobic cave", { :east => :largecave, :west => :pathway1 } )
my_dungeon.add_room(:pathway1, "Narrow Path", "A narrow pathway", { :east => :smallcave, :west => :caveentry } )
my_dungeon.add_room(:caveentry, "Cave Entrance", "The entrance to the cave", { :east => :pathway1 } )
my_dungeon.start(:largecave)
#my_dungeon.go(:east)

valid = false
until valid
    print " > "
    choice = $stdin.gets.chomp
    case choice
        when "east" , "west" , "north" , "south"
            my_dungeon.go(choice.to_sym)
        when "done", "quit", "exit"
            valid = true
        else
            puts "Invalid choice!"
    end
end

