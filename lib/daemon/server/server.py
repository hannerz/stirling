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

from stirling.lib.obj.spec.player import Player
from stirling.lib.obj.room import Room

class StirlingServer():
    def __init__(self, addr):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
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
            elif conn in self.connections:
                recv_data = conn.recv(1024).decode()
                if recv_data == '':
                    # Connection closed.
                    conn.close()
                    if conn in self.connections_player: del self.connections_player[conn]
                    self.connections.remove(conn)
                else:
                    if conn in self.logging_in:
                        # Outline the login process here!
                        username=''.join(random.choice(string.ascii_lowercase) for x in range(8))
                        player = Player(username, conn)
                        self.connections_player[conn] = player
                        self.logging_in.remove(conn)
                        conn.send(b'In theory, you should be logged in.\n')
                    else:
                        # If they've been logged in, pass the text to the player's
                        # object.
                        player = self.connections_player[conn]
                        player.handle_data(recv_data)
                        conn.send(b'At this point, this is where test functions run.\n')
                        # TEST FUNCTIONS GO HERE.  yes it's hackish, no I don't care.
                        from stirling.lib.daemon.database import Database
    def handle_forever(self):
        while True:
            self.handle()

def runserver():
    server = StirlingServer(('localhost', 5878))
    try:
        server.handle_forever()
    except KeyboardInterrupt:
        print('recived ^C, closing down')
        print(c.connections)
        [c.close() for c in server.connections]
        print(c.connections)
        server.socket.close()
        print('sockets closed, goodbye')
        raise
    except:
        raise

