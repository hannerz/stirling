"""
/lib/std/player.py
abzde@Stirling 100411

    The base player object - it contains the functions that are truly unique 
to players.
"""

from stirling.lib.obj.living import Living

class Player(Living):
    def __init__(self, username, conn):
        super(Player, self).__init__()
        self.name = username
        self.connection = conn

    def tell(self, data):
        super(Player, self).tell(data)
        self.connection.send(bytes(data, 'UTF-8'))

    def handle_data(self, data):
        self.parse_line(data)
