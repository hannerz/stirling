"""
/lib/server/server.py
abzde@Stirling
280411 emsenn@Stirling

The main socket server of Stirling.  Really overly simple at the moment, 
but as we're just getting started, not too set on what we need.
"""

import socket
import select
import random
import string

from stirling.obj.spec.daemon import Daemon
from stirling.obj.spec.player import Player
from world.dev.room.garden import Garden

class StirlingServer(Daemon):
    def __init__(self, addr):
        super(StirlingServer, self).__init__()
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.socket.bind(addr)
        self.socket.listen(10)
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
                new_conn.send(b'Welcome to the Stirling Engine.  Please hit enter.\n')
                self.info('New player connected.')
            elif conn in self.connections:
                recv_data = conn.recv(1024).decode()
                if recv_data == '':
                    # Connection closed.
                    conn.close()
                    self.info('Player {0} disconnected.'.format(self.connections_player[conn].name))
                    if conn in self.connections_player: del self.connections_player[conn]
                    self.connections.remove(conn)
                else:
                    if conn in self.logging_in:
                        # Outline the login process here!
                        username=''.join(random.choice(string.ascii_lowercase) for x in range(8))
                        player = Player(conn)
                        player.set_name(username)
                        self.connections_player[conn] = player
                        foobar = Garden()
                        player.move(foobar)
                        self.logging_in.remove(conn)
                        conn.send(b'You are now logged in, congrats.\n')
                        self.info('Player logged in as {0}'.format(username))
                    else:
                        # If they've been logged in, pass the text to the player's
                        # object.
                        player = self.connections_player[conn]
                        self.debug('Received data from {0}: {1}'.format(player.name, recv_data))
                        player.handle_data(recv_data)
    def handle_forever(self):
        while True:
            self.handle()

def runserver():
    server = StirlingServer(('localhost', 5878))
    try:
        server.handle_forever()
    except KeyboardInterrupt:
        server.info('Received ^C, closing down')
        for c in server.connections:
            c.close()
        server.socket.close()
        server.info('Sockets closed, goodbye')
        exit()
