My missunderstanding of DM1 (FECA) messages grows by the day...
if i send the message 18FECA00#55FFB804030AFFFF, the cluster displays the diagnosis message 16416.
if i send the message 18FECA00#55FF0804030AFFFF, the cluster displays the diagnosis message 16416.

I think I've cracked it! 
The encoding is done using version 1 of standard, but with a mask of 0x0F of byte 3(closest to can id).
