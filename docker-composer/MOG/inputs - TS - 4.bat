@echo off
start ffmpeg -re -stream_loop -1 -i baroskha_timecode.ts -vcodec copy -acodec copy -mpegts_flags resend_headers -f rtp_mpegts rtp://sagres:2000
start ffmpeg -re -stream_loop -1 -i endblue.ts -vcodec copy -acodec copy -mpegts_flags resend_headers -f rtp_mpegts rtp://sagres:2002
start ffmpeg -re -stream_loop -1 -i endgreen.ts -vcodec copy -acodec copy -mpegts_flags resend_headers -f rtp_mpegts rtp://sagres:2004
start ffmpeg -re -stream_loop -1 -i endred.ts -vcodec copy -acodec copy -mpegts_flags resend_headers -f rtp_mpegts rtp://sagres:2006



ffmpeg -i /dev/video0 -vcodec copy -acodec copy -mpegts_flags resend_headers -f rtp_mpegts rtp://147.228.242.97:2006
