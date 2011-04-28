"""
/lib/special/database.py
emsenn@Stirling 190411

    The daemon object for talking to the database
"""
import logging
logger = logging.getLogger(__name__)
logger.debug('Imported')

from pymongo import Connection

class Database(Connection):
    def __init__(self):
        super(Database, self).__init()
