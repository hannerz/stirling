from stirling.lib.obj.room import Room

class Cafe(Room):
    def __init__(self):
        super(Cafe, self).__init__()
        self.set_name('cafe')
        self.set_desc('This is a cafe.')
#       self.set_exits(['east':'stirling.world.dev.room.courtyard'])
