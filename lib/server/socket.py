"""
/lib/server/socket.py
abzde@Stirling
100411

The main socket server of Stirling.  Really overly simple at the moment, 
but as we're just getting started, not too set on what we need.
"""

import socket
import select
import random
import string

from stirling.lib.std.player import Player

class StirlingServer():
    def __init__(self, addr):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.setblocking(0)
        self.socket.bind(addr)
        self.socket.listen(5)
        self.connections = []
        self.logging_in = []
        self.connections_player = {} #{connection: player} mapping

    def handle(self):
        # Could someone explain what these are for? -- emsenn
        r, w, e = select.select([self.socket] + self.connections, [], [], 5)
        for conn in r:
            if conn is self.socket:
                (new_conn, addr) = conn.accept()
                self.connections.append(new_conn)
                # Add them to the login queue.
                self.logging_in.append(new_conn)
                # Connects are shown this first.
                new_conn.send(b'Welcome to the Stirling Engine.\n')
            elif conn in self.logging_in:
                    # Outline the login process here!
                    username=random.choice(string.ascii_lowercase)
                    player = Player(username, conn)
                    self.connections_player[conn] = player
                    self.logging_in.remove(conn)
                    conn.send(b'At this point, this is where test functions run.\n')
                    # TEST FUNCTIONS GO HERE.  yes it's hackish, no I don't care.
                    player.set_name(username)
                    foobar = Player('bacon!', conn)
                    foobar.set_name(432)
                    player.move(foobar)
                    player.tell('Player environment: '+player.environment.name+'\n')
                    for bar in foobar.inventory:
                        player.tell('bar: '+bar.name+'\n')
            else:
                # If they've been logged in, pass the text to the player's
                # object.
                # abzde - this passes funky markup - b'foobar\r\n'  Fix plz.
                self.connections_player[conn].handle_data(conn.recv(1024))

    def handle_forever(self):
        while True:
            self.handle()

def runserver():
    server = StirlingServer(('localhost', 5878))
    server.handle_forever()

