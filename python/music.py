# music.py

# /// script
# dependencies = ["music_tag"]
# ///

import os
import music_tag
import json

def saveTags(path, file, tags, printTags=False):
    f = music_tag.load_file(path+file)
    for key in tags:
        f[key] = tags[key]
        if printTags and key=='tracknumber':
            print(file, key, f[key])
    f.save()

def printTags(file, tags):
    f = music_tag.load_file(file)
    for key in tags:
        print(f[key])

def listFiles(path):
    fileList = os.listdir(path)
    return fileList

def getTrackNumber(file, genre):
    if genre == 'Varnam':
        trackList = {'aa':1, 'p':2, 'anu':3, 'mukthayi':4, 'ms':4, 'c':5, 'cs1':6, 'cs2':7, 'cs3':8, 'cs4':9, 'cs5':10}
    elif genre == 'Kriti':
        trackList = {'aa':1, 'p':2, 'anu':3, 'c':4, 'c1':5, 'c2':6, 'c3':7, 'c4':8, 'c5':9, 'c6':10, 'c7':11, 'c8':12, 'c9':13, 'c10':14}

    file = file.lower()
    for key in trackList:
        if key in file:
            track = trackList[key]
    return track
    
def readTags(path):
    with open(path+'info.json', 'r') as j:
        tags = json.loads(j.read())
    return tags

def executeCommand(folder, route):
    path = route + folder
    sCmd = 'for i in ' + path + '*.ogg; do ffmpeg -i "$i" -b:a 128k -ar 44100 "${i%.*}.mp3"; done'
    print('Success:', sCmd)
    os.system(sCmd)
    sCmd = "rm -rf " + path + "*.ogg"
    os.system(sCmd)
    print('Success:', sCmd)
    return
    
def main():
    
    folder = "SreeGanapathini/"

    with open(path+'~/musicFilePath.json', 'r') as j:
        filePaths = json.loads(j.read())

    executeCommand(folder, filePaths['routeSpace'])

    path = filePaths['route'] + folder
    tags = readTags(path)
    allFiles = sorted(listFiles(path))
    for item in allFiles:
        if item.endswith(".mp3"):
            tags['tracknumber'] = getTrackNumber(item[:-4], tags['genre'])
            saveTags(path, item, tags, True)

# Standard boilerplate to call the main() function to begin
# the program.
if __name__ == '__main__':
    main()    

#    allTags = ['album','albumartist','artist','artwork','comment','compilation','composer','discnumber','genre','lyrics','totaldiscs','totaltracks','tracknumber','tracktitle','year','isrc','bitrate','codec','length','channels','bitspersample','samplerate']
