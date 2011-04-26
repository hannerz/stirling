from stirling.lib.obj.room import Room

class Doge(Room):
    def __init__(self):
        super(Doge, self).__init__()
        set_short('Doge and Biscuit')
        set_desc('This is a small dark bar in Ackian Training Camp 07B, fondly '
          'called the Doge and Biscuit.  It is here mainly to take newcomer\'s '
          'money and perhaps their sanity.  There are lots of candles, and '
          'oddly, no windows anyway.  An unventilated alcohol-serving building '
          'with lots of open flames.  Hmm.')
        # set_exits({'south':'world.dev.room.cherry4']})
