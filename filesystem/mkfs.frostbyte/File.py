import Defenitions
import struct

from Attribute import Attribute
from time import time

class File:
    def __init__(self, filename: str):
        ftime = int(time())

        self.fileName = Attribute(Defenitions.ATTRIB_ID_FNAME, filename)
        self.fileCDate = Attribute(Defenitions.ATTRIB_ID_FCDATE, ftime)
        self.fileMDate = Attribute(Defenitions.ATTRIB_ID_FMDATE, ftime)
    
    def StoreFileData(self, data_buffer):
        self.fileData = data_buffer
    
    def FileHeader(self):
        return (
            struct.pack('<q', self.fileName.attributeId) +
            self.fileName.attributeValue.encode('ASCII') + b'\0' +
            struct.pack('<q', self.fileCDate.attributeId) + struct.pack('<q', self.fileCDate.attributeValue) +
            struct.pack('<q', self.fileMDate.attributeId) + struct.pack('<q', self.fileMDate.attributeValue)
        )