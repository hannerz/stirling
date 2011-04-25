#!/usr/bin/python3.2

import sys
import logging

log = logging.getLogger('main')
log.setLevel(logging.DEBUG)
log.debug('main')

sys.path.append('../')
from stirling.lib.server.socket import  runserver

try:
    runserver()
except:
    log.debug('exception!', exc_info=sys.exc_info())
    pass
