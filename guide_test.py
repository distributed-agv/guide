import guidepy
import redis

if __name__ == '__main__':
    commit_script = open('commit.lua', 'r').read()
    recover_script = open('recover.lua', 'r').read()
    getlock_script = open('getLock.lua', 'r').read()
    r = redis.Redis("127.0.0.1", 6379)
    commit_script_sha = r.script_load(commit_script)
    recover_script_sha = r.script_load(recover_script)
    getlock_script_sha = r.script_load(getlock_script)
    guide = guidepy.make_guide(2, 5, 5, "127.0.0.1", 6379, getlock_script_sha, commit_script_sha, recover_script_sha)
    while True:
        line = raw_input()
        tokens = line.split()
        car_id = int(tokens[0])
        seq = int(tokens[1])
        cur_row_idx = int(tokens[2])
        cur_col_idx = int(tokens[3])
        last_row_idx = int(tokens[4])
        last_col_idx = int(tokens[5])
        dst_row_idx = int(tokens[6])
        dst_col_idx = int(tokens[7])
        try:
            print guidepy.get_next_step(
                guide,
                car_id,
                seq,
                cur_row_idx,
                cur_col_idx,
                last_row_idx,
                last_col_idx,
                dst_row_idx,
                dst_col_idx,
            )
        except RuntimeError:
            print 'error'
