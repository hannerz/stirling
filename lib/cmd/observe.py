import logging
logger = logging.getLogger(__name__)
logger.debug('Imported')

def do_observe(obj, target="here"):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    if target is "here":
        obj.tell(obj.environment.desc())
    else:
        obj.tell("Sorry, this command can't handle arguments yet")

