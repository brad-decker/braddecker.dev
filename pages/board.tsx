import React, { useState, useEffect } from 'react';
import Card from '@material-ui/core/Card';
import { makeStyles, Grid, createStyles, CssBaseline, IconButton } from '@material-ui/core';
import Add from '@material-ui/icons/Add';
import RightArrow from '@material-ui/icons/ArrowRight';
import LeftArrow from '@material-ui/icons/ArrowLeft';

const useStyles = makeStyles(theme =>
  createStyles({
    container: {
      display: 'flex',
      width: '100%',
      backgroundColor: '#ECEEEE',
      minHeight: '100vh',
    },
    root: {
      flexGrow: 1,
      margin: '10px 25px',
    },
    card: {
      marginBottom: '5px',
      padding: '5px',
    },
    firstColumn: {
      paddingLeft: '0',
    },
    header: {
      padding: '10px 15px',
      textAlign: 'center',
      color: '#FFF',
    },
    first: {
      backgroundColor: '#8E6E95',
    },
    second: {
      backgroundColor: '#35A95C',
    },
    third: {
      backgroundColor: '#344759',
    },
    fourth: {
      backgroundColor: '#E8741E',
    },
  }),
);

function removeItemFromArray(arr, idx) {
  const copy = arr.slice();
  copy.splice(idx, 1);
  return copy;
}

export default () => {
  const classes = useStyles();
  const [columnState, setState] = useState<
    Record<string, { header: string; className: string; cards: { content: string }[] }>
  >({
    0: {
      header: 'groomed',
      className: `${classes.header} ${classes.first}`,
      cards: [{ content: 'content' }, { content: 'content' }],
    },
    1: {
      header: 'In Progress',
      className: `${classes.header} ${classes.second}`,
      cards: [{ content: 'content' }, { content: 'content' }],
    },
    2: {
      header: 'Review',
      className: `${classes.header} ${classes.third}`,
      cards: [{ content: 'content' }, { content: 'content' }],
    },
    3: {
      header: 'Done',
      className: `${classes.header} ${classes.fourth}`,
      cards: [{ content: 'content' }, { content: 'content' }],
    },
  });

  useEffect(() => {
    const item = window.localStorage.getItem('boardState');
    if (item) {
      setState(JSON.parse(item));
    }
  }, []);

  useEffect(() => {
    window.localStorage.setItem('boardState', JSON.stringify(columnState));
  });

  return (
    <div className={classes.container}>
      <CssBaseline />
      <Grid container spacing={4} className={classes.root}>
        {Object.values(columnState).map((column, idx) => (
          <Grid item xs={6} sm={3}>
            <header className={column.className}>{column.header}</header>
            {column.cards.map((card, cardIdx) => (
              <Card className={classes.card}>
                <Grid spacing={1} container>
                  <Grid item xs={2}>
                    {idx !== 0 && (
                      <IconButton
                        onClick={() => {
                          setState(prevState => ({
                            ...prevState,
                            [idx - 1]: {
                              ...prevState[idx - 1],
                              cards: [...prevState[idx - 1].cards, card],
                            },
                            [idx]: {
                              ...prevState[idx],
                              cards: removeItemFromArray(prevState[idx].cards, cardIdx),
                            },
                          }));
                        }}
                      >
                        <LeftArrow />
                      </IconButton>
                    )}
                  </Grid>
                  <Grid item xs={8}>
                    <p>{card.content}</p>
                  </Grid>
                  <Grid item xs={2}>
                    {idx !== 3 && (
                      <IconButton
                        onClick={() => {
                          setState(prevState => ({
                            ...prevState,
                            [idx + 1]: {
                              ...prevState[idx + 1],
                              cards: [...prevState[idx + 1].cards, card],
                            },
                            [idx]: {
                              ...prevState[idx],
                              cards: removeItemFromArray(prevState[idx].cards, cardIdx),
                            },
                          }));
                        }}
                      >
                        <RightArrow />
                      </IconButton>
                    )}
                  </Grid>
                </Grid>
              </Card>
            ))}
            <div>
              <IconButton
                onClick={() => {
                  const newContent = window.prompt('What task do you need to do?', 'content');
                  setState(prevState => ({
                    ...prevState,
                    [idx]: {
                      ...prevState[idx],
                      cards: [...prevState[idx].cards, { content: newContent }],
                    },
                  }));
                }}
              >
                <Add />
              </IconButton>
              Add Card
            </div>
          </Grid>
        ))}
      </Grid>
    </div>
  );
};
