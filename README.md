# Mytorrent-Basic-peer-to-peer-file-sharing-system 

A basic peer to peer file sharing system.
commands:
Tracker:
1. ./tracker tracker_info.txt
2. Close Tracker:
quit

Peer:

a. Run Client: ./client <IP>:<PORT> tracker_info.txt
\
b. Create User Account: create_user <user_id> <passwd>
  \
  
c. Login: login <user_id> <passwd>

d. Create Group: create_group <group_id>

e. Join Group: join_group <group_id>

f. Leave Group: leave_group <group_id>

g. List pending join requests : list_requests <group_id>

h. Accept Group Joining Request: accept_request <group_id> <user_id>

i. List All Group In Network: list_groups

j. List All sharable Files In Group: list_files <group_id>

k. Upload File: upload_file <file_path> <group_id>

l. Download File: download_file <group_id> <file_name> <destination_path>

m. Logout: logout

n. Show_downloads: Show_downloads

Output format:

[D] [grp_id] filename

[C] [grp_id] filename

D(Downloading), C(Complete)

o. Stop sharing: stop_share <group_id> <file_name

Namaskaar
