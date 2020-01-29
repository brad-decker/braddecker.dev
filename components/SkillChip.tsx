import { Skill } from '../data/skills';
import { Icon, Avatar, Chip, makeStyles, createStyles } from '@material-ui/core';
import { useMemo } from 'react';

const useStyles = makeStyles(theme =>
  createStyles({
    root: {
      height: theme.spacing(6),
      borderRadius: theme.spacing(2),
      paddingTop: theme.spacing(1.5),
      paddingRight: theme.spacing(1.5),
      paddingBottom: theme.spacing(1.5),
      paddingLeft: theme.spacing(0.5),
      boxShadow: theme.shadows[4],
      '& .fa-php': {
        width: '1.20em',
      },
      '& .fa-gem': {
        width: '1.20em',
      },
    },
    icon: {},
  }),
);

export const SkillChip = ({ name, iconClass, logo }: Skill) => {
  const classes = useStyles();
  const additionalProps = useMemo(() => {
    if (iconClass) {
      return { icon: <Icon className={`${iconClass} ${classes.icon}`} /> };
    } else if (logo) {
      return { avatar: <Avatar src={logo} alt={name} /> };
    }
    return {};
  }, [iconClass, logo]);
  return <Chip className={classes.root} label={name} {...additionalProps} color="primary" />;
};
