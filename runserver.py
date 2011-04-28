#!/usr/bin/python3.2

import sys
import logging

logging.basicConfig(level=logging.DEBUG)
log = logging.getLogger(__name__)
log.debug('main')

sys.path.append('../')
from stirling.daemon.server.server import runserver

try:
    log.info('Starting server')
    runserver()
except SystemExit:
    exit()
except:
    log.debug('exception!', exc_info=sys.exc_info())
    pass
